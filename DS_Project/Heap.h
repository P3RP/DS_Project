#pragma once

template <class T>
void swap(T& one, T& two)
{
	T temp;
	temp = one;
	one = two;
	two = temp;
}

template<class T>
struct Heap
{
	void re_heap_down(int root, int bottom);
	void re_heap_up(int root, int bottom);
	T* elements;
	int num;
};

template<class T>
void Heap<T>::re_heap_down(int root, int bottom)
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (elements[root] < elements[maxChild])
		{
			swap(elements[root], elements[maxChild]);
			re_heap_down(maxChild, bottom);
		}
	}
}

template<class T>
void Heap<T>::re_heap_up(int root, int bottom)
{
	int parent;

	if (bottom > root)
	{
		parent = (bottom - 1) / 2;
		if (elements[parent] < elements[bottom])
		{
			swap(elements[parent], elements[bottom]);
			re_heap_up(root, parent);
		}
	}

}
