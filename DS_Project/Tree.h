#pragma once

#include "Queue.h"

enum order_type { PRE_ORDER, IN_ORDER, POST_ORDER };

template<class _Ty>
struct TreeNode
{
	_Ty info;
	TreeNode<_Ty>* left;
	TreeNode<_Ty>* right;
};


template<class _Ty>
class Tree
{
public:
	// Function : Class constructor
	// Pre : X
	// Post : X
	Tree();

	// Function : Class destructor
	// Pre : Class is initialized
	// Post : X
	~Tree();

	// Function : Make tree empty
	// Pre : X
	// Post : Make tree empty
	void make_empty();
	
	// Function : Check whether tree is full or not
	// Pre : X
	// Post : Return whether tree is full or not
	bool is_full();

	// Function : Check whether tree is empty or not
	// Pre : X
	// Post : Return whether tree is empty or not
	bool is_empty();

	// Function : Get size of tree
	// Pre : X
	// Post : Return size of tree
	int size();

	// Function : Check whether item is in tree or not
	// Pre : Tree is initialized
	// Post : Return whether item is in tree or not
	bool retrieve_item(_Ty& item);

	// Function : Insert item in tree
	// Pre : Tree is not full
	//		 Item is not in tree
	// Post : Item is in tree
	void insert_item(_Ty item);

	// Function : Delete item in tree
	// Pre : Tree is not empty
	//		 Item is in tree
	// Post : Item is not in tree
	void delete_item(_Ty item);

	// Function : Initialize tree in order
	// Pre : X
	// Post : Current position is prior to tree
	void reset_tree(order_type order);

	// Function : Get next item in tree
	// Pre : Tree must reset in order and save in queue
	// Post : Get item in order
	void get_next_item(order_type order, _Ty& item, bool& fin);

private:
	TreeNode<_Ty>* root;
	Queue<_Ty> pre_que;
	Queue<_Ty> in_que;
	Queue<_Ty> post_que;

	void _destroy(TreeNode<_Ty>*& tree);
	int _count_node(TreeNode<_Ty>* tree);
	void _search(TreeNode<_Ty>* tree, _Ty& item, bool& chk);
	void _insert(TreeNode<_Ty>*& tree, _Ty item);
	void _delete(TreeNode<_Ty>*& tree, _Ty item);
	void _delete_node(TreeNode<_Ty>*& tree);
	void _get_predecessor(TreeNode<_Ty>* tree, _Ty& item);

	void _pre_order(TreeNode<_Ty>* tree, Queue<_Ty>& que);
	void _in_order(TreeNode<_Ty>* tree, Queue<_Ty>& que);
	void _post_order(TreeNode<_Ty>* tree, Queue<_Ty>& que);
};

template<class _Ty>
Tree<_Ty>::Tree()
{
	root = nullptr;
}

template<class _Ty>
Tree<_Ty>::~Tree()
{
	make_empty();
}

template<class _Ty>
void Tree<_Ty>::make_empty()
{
	_destroy(root);
}

template<class _Ty>
void Tree<_Ty>::_destroy(TreeNode<_Ty> *& tree)
{
	if (tree != nullptr)
	{
		_destroy(tree->left);
		_destroy(tree->right);
		delete tree;
	}
}

template<class _Ty>
bool Tree<_Ty>::is_full()
{
	QNode<_Ty>* location;
	try
	{
		location = new QNode<_Ty>;
		delete location;
		return false;

	}
	catch (typename std::bad_alloc exception)
	{
		return true;
	}
}

template<class _Ty>
bool Tree<_Ty>::is_empty()
{
	return (root == nullptr);
}

template<class _Ty>
int Tree<_Ty>::size()
{
	return 0;
}

template<class _Ty>
int Tree<_Ty>::_count_node(TreeNode<_Ty>* tree)
{
	if (tree = nullptr)
		return 0;
	else
		return _count_node(tree->left) + _count_node(tree->right) + 1;
}

template<class _Ty>
bool Tree<_Ty>::retrieve_item(_Ty & item)
{
	bool chk = false;
	_search(root, item, chk);
	return chk;
}

template<class _Ty>
void Tree<_Ty>::_search(TreeNode<_Ty>* tree, _Ty & item, bool & chk)
{
	if (!chk)
	{
		if (tree == nullptr)
			chk = false;
		else if (tree->info < item)
			_search(tree->left, item, chk);
		else if (tree->info > item)
			_search(tree->right, item, chk);
		else
		{
			item = tree->info;
			chk = true;
		}
	}
}

template<class _Ty>
void Tree<_Ty>::insert_item(_Ty item)
{
	_insert(root, item);
}

template<class _Ty>
void Tree<_Ty>::_insert(TreeNode<_Ty>*& tree, _Ty item)
{
	if (tree == nullptr)
	{
		tree = new TreeNode<_Ty>;
		tree->info = item;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	else if (tree->info > item)
		_insert(tree->left, item);
	else
		_insert(tree->right, item);
}

template<class _Ty>
void Tree<_Ty>::delete_item(_Ty item)
{
	_delete(root, item);
}

template<class _Ty>
void Tree<_Ty>::_delete(TreeNode<_Ty>*& tree, _Ty item)
{
	if (tree->info < item)
		_delete(tree->left, item);
	else if (tree->info < item)
		_delete(tree->right, item);
	else
		_delete_node(tree);
}

template<class _Ty>
void Tree<_Ty>::_delete_node(TreeNode<_Ty>*& tree)
{
	_Ty data;
	TreeNode<_Ty>* tempPtr = tree;

	if (tree->left == nullptr)
	{
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == nullptr)
	{
		tree = tree->left;
		delete tempPtr;
	}
	else
	{
		_get_predecessor(tree->left, data);
		tree->info = data;
		_delete(tree->left, data);  // Delete predecessor node.
	}
}

template<class _Ty>
void Tree<_Ty>::_get_predecessor(TreeNode<_Ty>* tree, _Ty& item)
{
	while (tree->right != nullptr)
		tree = tree->right;
	item = tree->info;
}

template<class _Ty>
void Tree<_Ty>::reset_tree(order_type order)
{
	if (order == IN_ORDER)
		_in_order(root, in_que);
	else if (order == PRE_ORDER)
		_pre_order(root, pre_que);
	else if (order == POST_ORDER)
		_post_order(root, post_que);
}

template<class _Ty>
void Tree<_Ty>::_pre_order(TreeNode<_Ty>* tree, Queue<_Ty>& que)
{
	if (tree != nullptr)
	{
		que.enqueue(tree->info);
		_pre_order(tree->left, que);
		_pre_order(tree->right, que);
	}
}

template<class _Ty>
void Tree<_Ty>::_in_order(TreeNode<_Ty>* tree, Queue<_Ty>& que)
{
	if (tree != nullptr)
	{
		_in_order(tree->left, que);
		que.enqueue(tree->info);
		_in_order(tree->right, que);
	}
}

template<class _Ty>
void Tree<_Ty>::_post_order(TreeNode<_Ty>* tree, Queue<_Ty>& que)
{
	if (tree != nullptr)
	{
		_post_order(tree->right, que);
		_post_order(tree->left, que);
		que.enqueue(tree->info);
	}
}

template<class _Ty>
void Tree<_Ty>::get_next_item(order_type order, _Ty& item, bool& fin)
{
	fin = false;
	if (order == IN_ORDER)
	{
		in_que.dequeue(item);
		if (in_que.is_empty())
			fin = true;
	}
	else if (order == PRE_ORDER)
	{
		pre_que.dequeue(item);
		if (pre_que.is_empty())
			fin = true;
	}
	else if (order == POST_ORDER)
	{
		post_que.dequeue(item);
		if (post_que.is_empty())
			fin = true;
	}
}