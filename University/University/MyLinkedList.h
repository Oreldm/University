#ifndef __MYLINKEDLIST_H
#define __MYLINKEDLIST_H

#include <iostream>
using namespace std;

////////////////////////////////////////////
/////////////   Node Class	////////////////
///////////////////////////////////////////
template <class T>
class Node
{
private:
	T data; //the object information
	Node<T>* next; //pointer to the next node element

public:
	Node(T data=NULL, Node<T>* next=nullptr);
	void setData(const T& data);
	const T& getData() const;
	void setNext(Node* next);
	Node* getNext() const;
};

template <class T>
Node<T>::Node<T>(T data, Node<T>* next)
{
	this->data = data;
	this->next = next;
}

template <class T>
void Node<T>::setData(const T& data)
{
	this->data = data;
}

template <class T>
const T& Node<T>::getData() const
{
	return data;
}

template <class T>
void Node<T>::setNext(Node* next)
{
	this->next = next;
}
template <class T>
Node<T>* Node<T>::getNext() const
{
	return next;
}


////////////////////////////////////////////
/////////   LinkedList Class	////////////
///////////////////////////////////////////
template <class T>
class MyLinkedList
{
private:
	//attributes of linked list:
	Node<T>* head;

public:
	MyLinkedList();
	~MyLinkedList();
	Node<T>* getHead() const;	//cant return const because we can (and will) change the object.
	bool add(const T& other);
	bool remove(const T& other);	//remove the first match element.
	void print() const;
};

template <class T>
MyLinkedList<T>::MyLinkedList<T>()
{
	this->head = nullptr;
}

template <class T>
MyLinkedList<T>::~MyLinkedList()
{
	Node<T>* temp;
	if (head != nullptr)	//there is elements in the list.
	{
		while (head->getNext() != nullptr)
		{
			temp = head;
			head = head->getNext();
			delete []temp;
		}
		delete []head;
	}
}

template <class T>
Node<T>* MyLinkedList<T>::getHead() const
{
	return head;
}

template <class T>
bool MyLinkedList<T>::add(const T& data)
{
	Node<T>* newNode = new Node<T>(data);
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node<T>* temp = head;
		while (temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}
		temp->setNext(newNode);
	}
	return true;
}

template <class T>
bool MyLinkedList<T>::remove(const T& data)
{
	bool found=false;
	Node<T>* tempToLink = nullptr;
	Node<T>* tempToRemove = head;
	if (tempToRemove == nullptr)	//if list is empty
		return false;
	else if (tempToRemove->getData() == data)	//if need to delete the head (necessery because maybe there is no getNext() available).
	{
		Node<T>* temp = head->getNext();
		delete []head;
		head=temp;
		return true;
	}
	else	//delete from second element and so on..
	{
		while (tempToRemove->getData() != data && tempToRemove->getNext() != nullptr)
		{
			tempToLink=tempToRemove;
			tempToRemove=tempToRemove->getNext();
			if (tempToRemove->getData() == data)
				found = true;
		}
	}
	if (found == true)
	{
		Node<T>* temp = tempToRemove->getNext();
		delete []tempToRemove;
		tempToLink->setNext(temp);
	}
	return false;
}


template <class T>
void MyLinkedList<T>::print() const
{
	Node<T>* temp = this->getHead();
	while(temp != nullptr)
	{
		cout << temp->getData() << ", ";
		temp = temp->getNext();
	}
	cout << "\b\b" << "." << endl; // =)
}


#endif