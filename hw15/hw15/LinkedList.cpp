#include "LinkedList.h" 
#include <iostream>
#include <limits>


LinkedListNode::LinkedListNode(int VALUE, LinkedListNode* PREVIOUS , LinkedListNode* NEXT)
	: data(VALUE),
	previous(PREVIOUS),
	next(NEXT)
{
	//nothing here
}

LinkedList::LinkedList()
	: head(nullptr)
{

	//nothinghere ... 
}

LinkedList::~LinkedList()
{
	while (Empty() == false)
	{
		PopFront();
	}
}


bool LinkedList::Empty()
{

	return head == nullptr;
}



void LinkedList::PushFront(int VALUE)
{
	if (Empty() == true)
	{
		//no elements
		head = new LinkedListNode(VALUE);
		
	}
	else
	{
		//at least 1 element 
		LinkedListNode* NewNode = new LinkedListNode(VALUE, nullptr, head);
		head->previous = NewNode;
		head = NewNode;

	}


}

void LinkedList::PopFront()
{
	if (Empty() == false)
	{
		

		//what size? 
		if (Size() == 1)
		{
			//1 element 
			delete head;
			head = nullptr;
		}
		else
		{
			//2 or more
			LinkedListNode* ToDelete = head;
			head->next->previous = nullptr;
			head = head->next;
			delete ToDelete;


		}
		

	}
}

int LinkedList::Size() const
{
	int count = 0;
	LinkedListNode* current = head;
	while (current != nullptr)
	{
		++count;
		current = current->next;

	}
	return count;
}

int LinkedList::operator[](int INDEX)
{
	if ((INDEX < 0) || (INDEX >= Size()))
	{
		return std::numeric_limits<int>::min();
	}

	LinkedListNode* current = head;
	for (int i = 0; i < INDEX; ++i)
	{
		current = current->next;
	}
	return current->data;
}

int LinkedList::Find(int value)
{
	int index = 0;
	LinkedListNode* current = head;
	while (current != nullptr)
	{
		if (value == current->data)
		{
			return index;
		}
		++index;
		current = current->next;
	}
	return -1;
}

void LinkedList::Insert(int INDEX, int VALUE)
{
	if ((Empty() == true) || (INDEX <= 0))
	{
		//first element
		PushFront(VALUE);
	}
	else if (INDEX >= Size()-1)
	{
		//last element
		LinkedListNode* prev = nullptr;
		LinkedListNode* current = head;
		while(current != nullptr)
		{
			prev = current;
			current = current->next;
		}
		//prev is pointing to last node
		LinkedListNode* newNode = new LinkedListNode(VALUE, prev);
		prev->next = newNode;
	}
	else
	{
		//anything in between 
		LinkedListNode* current = head;
		for (int i = 0; i < INDEX; ++i)
		{
			current = current->next;
		}
		//current is pointing to node
		LinkedListNode* newNode = new LinkedListNode(VALUE, current->previous, current);
		current->previous-> next= newNode;
		current->previous = newNode;





	}


}

void LinkedList::Erase(int INDEX)
{
	if ((INDEX <= 0) || (Size() <= 1))
	{
		PopFront();
	}
	
	else if (INDEX >= Size() - 1)
	{
		//has to be previous element 
		LinkedListNode* prev = nullptr;
		LinkedListNode* current = head;
		while (current != nullptr)
		{
			prev = current;
			current = current->next;
		}
		//prev is pointing to last node
		prev->previous->next = nullptr;
		delete prev;
	
	}
	else
	{
		//has to be both previous and next element
		LinkedListNode* current = head;
		for (int i = 0; i < INDEX; ++i)
		{
			current = current->next;
		}
		//current is pointing to node 
		current->previous->next = current->next;
		current->next->previous = current->previous;
		delete current;
	}	
	
	


}

std::ostream& operator<<(std::ostream& ostr, const LinkedList& rhs)
{
	// TODO: insert return statement here
	ostr << "LIST: ";
	LinkedListNode* current = rhs.head;
	while (current != nullptr)
	{
		ostr << " " << current->data;
		current = current->next;

	

	}


	ostr << "SIZE: " << rhs.Size() << std::endl;
	return ostr;

}
