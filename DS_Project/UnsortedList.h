#pragma once

// Data Structure "Unsorted List with Linked node"

template <class _Ty>
struct Node
{
	_Ty info;
	Node* prev;
	Node* next;
};

template <class _Ty>
class UnsortedList
{
public:
	// Class constructor
	UnsortedList();

	// Class destructor
	~UnsortedList();

	// Function : Check whether list is full or not
	// Pre : X
	// Post : Return whether list is full or not
	bool is_full();

	// Function : Check whether list is empty or not
	// Pre : X
	// Post : Return whether list is empty or not
	bool is_empty();

	// Function : Make list empty
	// Pre : X
	// Post : Make list empty
	void make_empty();

	// Function : Get size of list
	// Pre : X
	// Post : Return size of list
	int size();

	// Function : Check whether item is in list or not
	// Pre : List is initialized
	// Post : Return whether item is in list or not
	bool retrieve_item(_Ty& item);

	// Function : Insert item in list
	// Pre : List is not full
	//		 Item is not in list
	// Post : Item is in list
	void insert_item(_Ty item);

	// Function : Delete item in list
	// Pre : List is not empty
	//		 Item is in list
	// Post : Item is not in list
	void delete_item(_Ty item);

	// Function : Initialize current position
	//			  to first position
	// Pre : X
	// Post : Current position is prior to list
	void reset_list();

	// Function : Get next item in list
	// Pre : Current positon is defined
	//		 item in current position is not last item in list
	// Post : Return item in current position
	//		  Current position is updated to next position
	_Ty& get_next_item();
	
private:
	int length;
	Node<_Ty>* list_data;
	Node<_Ty>* current_pos;
};

template<class _Ty>
UnsortedList<_Ty>::UnsortedList()
{
	length = 0;
	list_data = nullptr;
	current_pos = nullptr;
}

template<class _Ty>
UnsortedList<_Ty>::~UnsortedList()
{
	make_empty();
}

template<class _Ty>
bool UnsortedList<_Ty>::is_full()
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
bool UnsortedList<_Ty>::is_empty()
{
	return (length == 0);
}

template<class _Ty>
void UnsortedList<_Ty>::make_empty()
{
	Node<_Ty>* temp;
	while (list_data != nullptr)
	{
		temp = list_data;
		list_data = list_data->next;
		delete temp;
	}
	length = 0;
}

template<class _Ty>
int UnsortedList<_Ty>::size()
{
	return length;
}

template<class _Ty>
bool UnsortedList<_Ty>::retrieve_item(_Ty& item)
{
	bool search = false;
	Node<_Ty>* temp = list_data;

	while (temp != nullptr && !search)
	{
		if (item == temp->info)
		{
			search = true;
			item = temp->info;
		}
		else
		{
			temp = temp->next;
		}
	}
	return search;
}

template<class _Ty>
void UnsortedList<_Ty>::insert_item(_Ty item)
{
	if (list_data != nullptr)
	{
		Node<_Ty>* temp = list_data;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new Node<_Ty>;
		temp->next->info = item;
		temp->next->prev = temp;
		temp->next->next = nullptr;
	}
	else
	{
		list_data = new Node<_Ty>;
		list_data->info = item;
		list_data->next = nullptr;
		list_data->prev = nullptr;
	}
	length++;
}

template<class _Ty>
void UnsortedList<_Ty>::delete_item(_Ty item)
{
	Node<_Ty>* temp = list_data;

	while (temp != nullptr)
	{
		if (temp->info == item)
			break;
		temp = temp->next;
	}
	
	if (temp != nullptr)
	{
		if (temp->next != nullptr)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
		else
		{
			temp->prev->next = nullptr;
			delete temp;
		}
		length--;
	}
}

template<class _Ty>
void UnsortedList<_Ty>::reset_list()
{
	current_pos = nullptr;
}

template<class _Ty>
_Ty & UnsortedList<_Ty>::get_next_item()
{
	if (current_pos == nullptr)
		current_pos = list_data;
	else
		current_pos = current_pos->next;
	return current_pos->info;
}
