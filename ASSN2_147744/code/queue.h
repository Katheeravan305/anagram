#pragma once
#ifndef main_queue_H
#define main_queue_H
#include<string>
using namespace std;


template<class T>
class queue //class to use queue data structure
{
private:
	struct queueNode 
	{
		T value;
		queueNode* next; //pointer that will point to the next value
	};
	queueNode* front; //starting of the queue
	queueNode* rear;//contains values after the front
	int count;

public:
	queue() { front = NULL, rear = NULL, count = 0; }//constructor
	~queue() { clear(); }//desstructor
	void enqueue(T); // function to put value inside the queue
	void dequeue(T &);//function to remove a value from queue
	bool isempty() const;//function to check a queue is empty or not
	void clear(); //function to clear all the queue values and make it empty
};

template<class T>
void queue<T>::enqueue(T w)// function to put value inside the queue
{
	queueNode* newnode=NULL; //node to hold the new data
	newnode = new queueNode; //creating a node
	newnode->value = w; //giving a value to the newnode node
	newnode->next = NULL;//pointing the next value of newnode to null

	if (isempty()) //checking whther queue is empty
	{
		front = newnode; 
		rear = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
	count++;
}

template<class T>
void queue<T>::dequeue(T &w)//function to remove a value from queue
{
	queueNode* nodeptr=NULL; 
	if (isempty()) //checking whether queue is empty
	{
		cout << "Queue is empty.\n";
	}
	else
	{
		w = front->value; //value that will be deleted from queue
		nodeptr = front; //declaring nodeptr as front
		front = front->next; //giving value of next pointer of front to front
		delete nodeptr; // removing  value from begining of queue
		count--;
	}
}

template<class T>
bool queue<T>::isempty() const//function to check a queue is empty or not
{
	if (front == NULL) //checking whether front value is null
		return true;   
	else
		return false;
}

template<class T>
void queue<T>::clear()//function to clear all the queue values and make it empty
{
	queueNode* nodeptr;
	while (!isempty()) //until the queue becomes empty the begining value in the queue will be deleted
	{
		nodeptr = front;
		front = front->next;
		delete nodeptr;
	}
	count = 0;
}

#endif

