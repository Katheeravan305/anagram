#pragma once
#ifndef main_linklist_H
#define main_linklist_H
#include<string>
using namespace std;


template <class T>
class Linklist
{
public :

	struct ListNode
	{
		T value;
		ListNode* next;  //pointer that will point to next node
		ListNode* permute=NULL; //pointer that will point to the anagrams
	};
	ListNode* head; //starting node of link list

public:
	void append(T); //function to append value to the main linklist
	void append2(T,T);//function to append annagrams to each node in the main list
	void display();//function to display all words
	void display2(T);//function to display anagrams of a searched word
	void display3(T, T);//function to create anagrams ofa  searched word starting with a specific letter
	void insert(T,T);//function to insert value into the list
	void deleteNode(T);//function to delete node
	void validatelist(T, int &);//function for validation of words.
	void displayana();//function to display all anagrams of all words
	Linklist() { head = NULL; }//constructor
	~Linklist();//destructor
};

template<class T>
Linklist<T>::~Linklist() //destructor
{
	ListNode* nodeptr;
	ListNode* nextnode;

	nodeptr = head;

	while (nodeptr != NULL)
	{
		nextnode = nodeptr->next;
		delete nodeptr;
		nodeptr = nextnode;
	}
}

template <class T>
void Linklist<T>::append(T w)//function to append value to the main linklist
{
	ListNode* newData;
	ListNode* nodePtr;
	
	newData = new ListNode;
	newData->value = w;
	newData->next = NULL;

	if (!head) //head has no value newnode will become head
	{
		head = newData;
	}
	else
	{
		nodePtr = head;

		while (nodePtr->next)  //looping until end of list
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newData; //adding  new node to the end of list
		
	}
}

template <class T>
void Linklist<T>::append2(T w,T word)//function to append annagrams to each node in the main list
{
	//word is the words in the main link list
	//w is the anagram which will be appended using permute link list
	ListNode* newData; //node to hold the anagrams
	ListNode* nodePtr; //node used to traverse the main list
	newData = new ListNode; //creating new node
	newData->value = w; //adding value to newnode

	nodePtr = head; 
	while (nodePtr != NULL && nodePtr->value != word) //loops until it reaches word
	{
		nodePtr = nodePtr->next;
	}

	if (newData->value != word) //check whether the newdata is same with word to avoid repeatsion
	{
		while (nodePtr->permute)
		{
			nodePtr = nodePtr->permute;
		}

		nodePtr->permute = newData; //appending anagrams using permute pointer
	}
}

template <class T>
void Linklist<T>::display()//function to display all words
{
	ListNode* nodePtr;
	int num = 1;
	nodePtr = head;

	cout << endl;
	while (nodePtr)
	{
		cout << num << " " << nodePtr->value << endl; //display all the words in the main list.
		nodePtr = nodePtr->next;
		num += 1;
	}
}

template <class T>
void Linklist<T>::display2(T w)//function to display anagrams of a searched word
{
	ListNode* nodePtr;
	ListNode* node;
	int num = 1;

	if (!head)
	{
		cout << "List is empty.\n";
	}
	else
	{
		nodePtr = head;
		while (nodePtr->value != w) //searching for the node that has the same as the word entered by user
		{
			nodePtr = nodePtr->next;
		}
		cout << endl;
		while (nodePtr)  //loops to print all the anagrams of the word searched by user
		{
			cout << num << " " << nodePtr->value << endl;
			nodePtr = nodePtr->permute;
			num += 1;
		}
		cout << "\nWord " << w << " has " << num - 1 << " different anagrams.\n\n";		
	}
}

template <class T>
void Linklist<T>::display3(T w,T a)//function to create anagrams of a searched word starting with a specific letter
{
	ListNode* nodePtr;
	int num = 1, count = 0;
	string word;
	nodePtr = head;

	if (!head)
	{
		cout << "List is empty.\n";
	}
	else
	{
		while (nodePtr->value != w)
		{
			nodePtr = nodePtr->next; //searching for the node with same value as searched word using next pointer
		}
		cout << endl;
		while (nodePtr)  //displaying the node values which are the anagrams using permute pointer
		{
			word = nodePtr->value;
			if (word[0] == a[0])
			{
				cout << num << " " << word << endl;
				num += 1;
			}
			nodePtr = nodePtr->permute;
		}
		cout << "\nWord " << w << " has " << num - 1 << " different anagrams ";
		cout << "starting with " << a << ".\n\n";
	}
}

template<class T>
void Linklist<T>::insert(T w,T prev)//function to insert value into the list
{
	ListNode* nodePtr;
	ListNode* node;
	ListNode* newdata;

	int check=0;

	newdata = new ListNode;
	newdata->value = w;
	
	
	if (head->value==prev)
	{
		newdata->next = head->next;
		head->next = newdata;
	}
	else
	{
		nodePtr = head;
		node = head;
		while (nodePtr->value != prev)
		{
			nodePtr = nodePtr->next;
			node = nodePtr->next;
		}

		nodePtr->next = newdata;
		newdata->next = node;
	}
}

template<class T>
void Linklist<T>::deleteNode(T w)//function to delete node
{
	ListNode* nodePtr;
	ListNode* previousNode;
	ListNode* temp;
	ListNode* node;

	if (!head)
		return;

	if (head->value == w)
	{
		node=head;
		while (node->value != w)
		{
			node = node->next;
		}

		while (node)//deleteing all the anagrams first 
		{
			temp = node->permute;
			if (node->value != w)
			{
				delete node;
			}
			node = temp;
		}
		
		nodePtr = head;
		head = head->next;
		delete nodePtr;
	}
	else
	{
		nodePtr = head;
		while (nodePtr->value != w)
		{
			nodePtr = nodePtr->next;
		}

		while (nodePtr)//deleteing all the anagrams first 
		{
			temp = nodePtr->permute;
			if (nodePtr->value != w)
			{
				delete nodePtr;
			}
			nodePtr = temp;
		}

		node = head;
		previousNode = head;
		while (node->value != w)//deleting the node with value entered by user
		{
			previousNode = node;
			node = node->next;
		}

		if (node)
		{
			previousNode->next = node->next;
			delete node;
		}
	}
	cout << "Word " << w << " is deleted from the list together with its anagrams.\n\n";
}

template<class T>
void Linklist<T>::validatelist(T w, int & list)//function for validation of words.
{
	//This function is used to validate the words entered by user
	//It is used to detect if a new word added by user is already exist in the list and show error
	//also used when searching for a word , it will show error if the word enterd by user not already existing in the list.
	//because when seacrching a word it must be already existing in the list.
	ListNode* nodeptr;
	nodeptr = head;
	while (nodeptr)
	{
		if (nodeptr->value == w) 
		{ 
			list = 1; 
		}
		nodeptr = nodeptr->next;
	}
}

template<class T>
void Linklist<T>::displayana()
{
	ListNode *nodeptr;
	ListNode* print;
	
	nodeptr=head;
	while(nodeptr)
	{
		print =nodeptr;
		while(print)
		{
			cout<<print->value<<endl;
			print=print->permute;
		}
		nodeptr=nodeptr->next;
	}
}
#endif
