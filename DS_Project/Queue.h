#pragma once


template<class _Ty>
class FullQueue{};

template<class _Ty>
class EmptyQueue{};

template<class _Ty>
struct Node
{
	_Ty info;
	Node<_Ty>* next;
};

template<class _Ty>
class Queue
{
public:
	Queue();
	~Queue();

	void make_empty();
	bool is_empty();
	bool is_full();
	void enqueue(_Ty item);
	void dequeue(_Ty& item);
private:
	Node<_Ty>* front;
	Node<_Ty>* rear;
};

template<class _Ty>
Queue<_Ty>::Queue()
{
	front = nullptr;
	rear = nullptr;
}

template<class _Ty>
Queue<_Ty>::~Queue()
{
	make_empty();
}

template<class _Ty>
void Queue<_Ty>::make_empty()
{
	Node<_Ty>* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	rear = nullptr;
}

template<class _Ty>
bool Queue<_Ty>::is_empty()
{
	return (front == nullptr);
}

template<class _Ty>
bool Queue<_Ty>::is_full()
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
void Queue<_Ty>::enqueue(_Ty item)
{
	if (is_full())
		throw FullQueue<_Ty>();
	else
	{
		Node<_Ty>* new_node;
		new_node = new Node<_Ty>;
		new_node->info = item;
		new_node->next = nullptr;

		if (rear == nullptr)
			front = new_node;
		else
			rear->next = new_node;
		rear = new_node;
	}
}

template<class _Ty>
void Queue<_Ty>::dequeue(_Ty & item)
{
	if (is_empty())
		throw EmptyQueue<_Ty>();
	else
	{
		Node<_Ty>* temp;

		temp = front;
		item = front->info;
		front = front->next;
		if (front == nullptr)
			rear = nullptr;
		delete temp;
	}
}
