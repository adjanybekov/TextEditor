#ifndef _LINKED_NODE_H_
#define _LINKED_NODE_H_
//this is a doubly Linked_List_Node
//#include <iostream>
template<class T>
class LinkedNode {
private:
	LinkedNode<T> *prev;
	LinkedNode<T> *next;
	T data;
public:
    /* Default constructor. Initialize member variables if needed. */ 
	LinkedNode();
	LinkedNode<T>* getNext() const;
	LinkedNode<T>* getPrev() const;
	
	/* returns a pointer pointing to member variable _data_. */
	T* getData();
	
	void setNext(LinkedNode<T> *newNext); 
	void setPrev(LinkedNode<T> *newPrev);
	void setData(T& newData);
};



template<class T>
LinkedNode<T>::LinkedNode(){
	prev = NULL;
	next = NULL;	
}

template<class T>
LinkedNode<T>* LinkedNode<T>::getNext() const
{

	return next;
}

template<class T>
LinkedNode<T>* LinkedNode<T>::getPrev() const
{
	return prev;
}

template<class T>
void LinkedNode<T>::setPrev(LinkedNode<T>* newPrev)
{
	prev = newPrev;
}

template<class T>
void LinkedNode<T>::setNext(LinkedNode<T>* newNext)//sets next adress to the element 
{
	next = newNext;

}

template<class T>
void LinkedNode<T>::setData(T& newData)
{
	data = newData;
}


template<class T>
T*  LinkedNode<T>::getData(){
	return &data;
}

#endif