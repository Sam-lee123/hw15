#pragma once
#include <iostream>

class LinkedListNode
{
public: 
	LinkedListNode(int VALUE, 
					LinkedListNode* PREVIOUS = nullptr,
					LinkedListNode* NEXT = nullptr);


	int data;
	LinkedListNode* previous;
	LinkedListNode* next;


};


class LinkedList
{
public: 
	LinkedList();
	~LinkedList();

	bool Empty();
	void PushFront(int VALUE);
	void PopFront();
	int Size() const;
	int operator[](int INDEX);
	int Find(int value);
	void Insert(int INDEX, int VALUE);
	void Erase(int INDEX);


	friend std::ostream& operator <<(std::ostream& ostr, const LinkedList& rhs);


	
private:
	LinkedListNode* head;

};