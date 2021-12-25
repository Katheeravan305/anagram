#pragma once
#ifndef main_stack_H
#define main_stack_H
#include<string>
using namespace std;

template<class T>
class stack
{
private:
	struct stackNode
	{
		T value; //variable that holds the value of a pointer
		stackNode* next; //pointer that will point to the next value
	};
	stackNode* top; //pointer that is at the top of the stack

public:
	stack() { top = NULL; } //constructor
	~stack(); //destructor
	void push(T); //function to enter value into the stack
	void pop(T &); //function to remove value from top of the stack
	bool isempty() const; //function to check whether stack is empty
};

template<class T>
stack<T>::~stack()
{
	stackNode* nodeptr;
	stackNode* nextnode;

	nodeptr = top;

	while (nodeptr != NULL)
	{
		nextnode = nodeptr->next;
		delete nodeptr;
		nodeptr = nextnode;
	}
}

template<class T>
void stack<T>::push(T w) //function to enter value into the stack
{
	stackNode* newnode = NULL; //new pointer to hold the value that will be pushed to the stack
	newnode = new stackNode; //creating new node
	newnode->value = w; //giving value to the node
	newnode->next = NULL; //pointing the newnode to null
	if (isempty()) //checking if stack is empty
	{
		top = newnode; //pushing value to the top of the stack
		newnode->next = NULL; //pointing the newnode to null
	}
	else
	{
		newnode->next = top; //pointing the newnode to top
		top = newnode; 
	}

}

template<class T>
void stack<T>::pop(T & w) //function to remove value from top of the stack
{
	stackNode* temp = NULL; //creating a new node
 
	if (isempty()) //checking if stack is empty
	{
		cout << "The stack is empty\n";
	}
	else
	{
		 //removing value from top of the stack
		w = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}

template<class T>
bool stack<T>::isempty() const //function to check whether stack is empty
{
	bool status;

	if (!top)
		status = true;
	else
		status = false;

	return status;
}

#endif
