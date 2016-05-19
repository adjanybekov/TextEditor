#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <cstdlib>
#include "LinkedNode.h"

template<class T>
class LinkedList {
private:
	LinkedNode<T> *head;
	LinkedNode<T> *tail;	
public:
    /* Default constructor. Initialize member variables. */ 
	LinkedList();//done 
	
	/* Default destructor. Free all the memory used. */
	~LinkedList();
	
	/* Returns head of the linked list. */
	LinkedNode<T>* getHead() const;//+

	
	/* Returns tail of the linked list. */
	LinkedNode<T>* getTail() const;//+
	
	/* Returns idx-th node of the linked list under 0-based numbering.
	 */
	LinkedNode<T>* getNodeAt(int idx) const;//???
	
	/* Inserts a new node containing _data_ at the beginning of the linked list.
	 */
	void insertFirst(T &data);	//+
	
	/* Inserts a new node containing _data_ after _node_.
	 */
	void insertNode(LinkedNode<T>* node, T& data);//+
		
	/* Deletes _node_ from the linked list
	 */
	void deleteNode(LinkedNode<T>* node); //+
};








template <class T>
LinkedList<T>::LinkedList(){
	head = NULL;
	tail = NULL;
}


template <class T>
LinkedList<T>::~LinkedList(){
	LinkedNode<T>* node = head;//new LinkedNode<T>;

while(node!=tail){
	deleteNode(node);
	node = node->getNext();
}

	//head = NULL;
	//tail = NULL;
}

template <class T>
LinkedNode<T>* LinkedList<T>::getHead()const{
	return head;
}



template <class T>
LinkedNode<T>* LinkedList<T>::getTail() const{
	return tail;
}



//Do duda Vse Horowo 

template<class T>
void LinkedList<T>::insertFirst(T &data){
LinkedNode<T> *ln = new LinkedNode<T>;
ln->setData(data);
head = (ln);
tail = ln;
ln->setNext(NULL);
ln->setPrev(NULL);

}


template<class T>
void LinkedList<T>::insertNode(LinkedNode<T>* node, T& data){


	LinkedNode<T> *newNode = new LinkedNode<T>;//new Node(x,NULL);
	//newNode = NULL;
	newNode->setData(data);

	if(node == tail){//if the node is to be inserted after the head  and there is an element
		//insertFirst(data);
		//newNode->setData(data);
		//(newNode) = node;
		node->setNext(newNode);
		newNode->setPrev(node);
		newNode->setNext(NULL);
		tail = newNode;
		//head = newNode;

}

	else if (node!=tail){ // insert in the middle 
		
		newNode->setPrev(node);
		newNode->setNext(node->getNext());
		node->getNext()->setPrev(newNode);
		//++
		node->setNext(newNode);

		//newNode->getNext()->setPrev(newNode);
		//neuther head nor tail need to be changed 

	}
	


	} 


template <class T>
LinkedNode<T>* LinkedList<T>::getNodeAt(int idx) const{

	LinkedNode<T> *ln = head;
	for(int i = 0; i < idx; i++)
	{
		ln = ln->getNext();
	}
	return ln;
}



template<class T>
void LinkedList<T>::deleteNode(LinkedNode<T>* node){
	/*if(head == tail){//node is alone
		//std::cout<<"wrong";
		delete node;
	}*/
	/*if(node == head){//node is the first node in the list 
		head = node->getNext();
		head->setPrev(NULL);
		delete  node;
	}*/



	if(node == tail){//if node is  the last node  in the list 
		tail = node->getPrev();
		node->getPrev()->setNext(NULL);
		node->setPrev(NULL);//
		//node->set()

		//node->getPrev->setNext(NULL);// Ambiguoys code
		
		
		delete node;
	}
	
	else if(node!=tail) { //node is in the middle has two sides
		node->getPrev()->setNext(node->getNext());
		node->getNext()->setPrev(node->getPrev());
		delete node;
	}

}


#endif

