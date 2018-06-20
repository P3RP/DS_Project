#pragma once

#include "Heap.h"
#define MAX_SIZE 100

template <class T>
class FullPQueue{};

template <class T>
class EmptyPQueue{};

template <class T>
class PQueue
{
public:
	PQueue();
	PQueue(int length);
	~PQueue();

	void make_empty();
	bool is_empty();
	bool is_full();
	void enqueue(T item);
	void dequeue(T& item);
private:
	Heap<T> items;
	int size;
	int capacity;
};

template<class T>
PQueue<T>::PQueue()
{
	items.elements = new T[MAX_SIZE];
	size = 0;
	capacity = MAX_SIZE;
}

template<class T>
PQueue<T>::PQueue(int length)
{
	items.elements = new T[length];
	size = 0;
	capacity = length;
}

template<class T>
PQueue<T>::~PQueue()
{
	delete[] items.elements;
}

template<class T>
void PQueue<T>::make_empty()
{
	size = 0;
}

template<class T>
bool PQueue<T>::is_empty()
{
	return (size == 0);
}

template<class T>
bool PQueue<T>::is_full()
{
	return (size == capacity);
}

template<class T>
void PQueue<T>::enqueue(T item)
{
	if (size == capacity)
		throw FullPQueue<T>();
	else
	{
		items.elements[size] = item;
		size++;
		items.re_heap_up(0, size - 1);
	}
}

template<class T>
void PQueue<T>::dequeue(T & item)
{
	if (size == 0)
		throw EmptyPQueue<T>();
	else
	{
		item = items.elements[0];
		items.elements[0] = items.elements[size - 1];
		size--;
		items.re_heap_down(0, size - 1);
	}
}

