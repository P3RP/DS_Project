#pragma once

#include "Queue.h"

enum order_type { PRE_ORDER, IN_ORDER, POST_ORDER };

template<class _Ty>
struct TreeNode
{
	_Ty info;
	TreeNode* left;
	TreeNode* right;
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

	// Function : Initialize current position
	//			  to first position
	// Pre : X
	// Post : Current position is prior to tree
	void reset_tree();

	// Function : Get next item in tree
	// Pre : Current positon is defined
	//		 item in current position is not last item in tree
	// Post : Return item in current position
	//		  Current position is updated to next position
	_Ty& get_next_item();

private:
	TreeNode<_Ty>* root;
	Queue<_Ty> pre_que;
	Queue<_Ty> in_que;
	Queue<_Ty> post_que;

	void _delete_node(TreeNode<_Ty>*& tree);
	int _count_node(TreeNode<_Ty>* tree);
	void _search(TreeNode<_Ty>* tree, _Ty& item, bool& chk);
	void _insert(TreeNode<_Ty>* tree, _Ty item);
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
	_delete_node(root);
}

template<class _Ty>
void Tree<_Ty>::_delete_node(TreeNode<_Ty> *& tree)
{
	if (tree != nullptr)
	{
		_delete_node(tree->left);
		_delete_node(tree->right);
		delete tree;
	}
}

template<class _Ty>
bool Tree<_Ty>::is_full()
{
	Node<_Ty>* location;
	try
	{
		location = new Node<_Ty>;
		delete location;
		return false;

	}
	catch (std::bad_alloc exception)
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
	_insert(root);
}

template<class _Ty>
void Tree<_Ty>::_insert(TreeNode<_Ty>* tree, _Ty item)
{
	if (tree == nullptr)
	{
		tree = new TreeNode<_Ty>;
		tree->info = item;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	else if (tree->info < item)
		_insert(tree->left, item);
	else
		_insert(tree->right, item);
}

template<class _Ty>
void Tree<_Ty>::delete_item(_Ty item)
{
	
}
