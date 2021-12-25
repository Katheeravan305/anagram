#include<iostream>
#include<fstream>
#include<string>
#include "queue.h"
#include "stack.h"
#include "linklist.h"
using namespace std;

void anagram(string,Linklist<string> & ,stack<string>, queue<string>); //function to creating anagram of a word

int main()
{
	Linklist<string> l; //object for linklist class
	queue<string> q;//object for queue class
	stack<string> s;//object for stack class

	fstream dataReadFile; //file declaration
	int option,num, qty, begin = 1;
	char menuchoice;
	string word,appending,filename;

	cout << "Enter file name that contains words : ";
	cin >> filename; //input filename that has all the words

	dataReadFile.open(filename); //opening file

	while (!dataReadFile) //input validation if the filename entered does not exist or cannot open
	{
		//while loop will loop  until the file entered by user can be opened
		cout << "\nError!!! Wrong File Name !!!\n";
		cout << "Enter correct file name that contains words : ";
		cin >> filename;
		dataReadFile.open(filename);
	}

	if (dataReadFile) //if the file is opened
	{
		while (!dataReadFile.eof()) //until the end of line in the file the while loop will loop
		{
			dataReadFile >> appending; //reading word from file
			l.append(appending);//function that adds the word read from file to main link list
			anagram(appending,l,s, q);//function that creates anagram for the word read from the file
		}
	}
	dataReadFile.close(); //closing file

	system("CLS");//clearing commmend prom

	while (begin == 1)//loop for main menu
	{
		system("CLS");
		cout << "\n!!!MAIN MENU!!!\n";  //main menu
		cout << "\nEnter a number according to the below options.\n";
		cout << "1.Display all the words in list.\n2.Search\n";
		cout << "3.Append word to list.\n4.Display Anagrams of All Words.\n5.Exit\n";
		cout << "Options:";//option that are given to user
		cin >> menuchoice;//each option will go to different case in switch.

		while (menuchoice != '1' && menuchoice != '2' && menuchoice != '3' && menuchoice != '4'&& menuchoice != '5')
		{//input validation for menuchoice
			cout << "Input the correct value.\n";
			cout << "Options:";
			cin >> menuchoice;//it will loop until input is correct
		}

		switch (menuchoice)
		{
			case'1': //when user choose option one above
			{
				system("CLS");
				cout << "\n\nWords that are in the list\n";
				l.display();//function to display all the words in the main link list
				system("PAUSE");
				break;//exiting the switch
			}
			case'2':
			{
				string search,nword;
				int check=0,menu=1,check2=0;
				char mchoice;
				system("CLS");
				cout<<"Enter the word that you want to search: ";
				cin>>search;
				l.validatelist(search, check);//function to check if the word enterd by user exist in the list
				while (check != 1)//input validation for word
				{
					//it will loop until the word entered by user already exist in the main link list 
					cout << "Error!!!The word you are searching does not exist in the list.\n";
					cout << "Enter correct word: ";
					cin >> search;
					l.validatelist(search, check);
				}
				while(menu==1)
				{
					system("CLS");
					cout<<"Searching...(WORD : "<<search<<")\n";
					cout<<"1.Display All Anagrams of Word.\n2.Display Anagrams of word staring with specific letter.\n";
					cout<<"3.Update word.\n4.Add word.\n5.Delete word.\n6.Exit\nOption: ";
					cin>>mchoice;
					while (mchoice != '1' && mchoice != '2' && mchoice != '3' && mchoice != '4' && mchoice != '5'&& mchoice != '6')
					{//input validation for mchoice
						cout << "Input the correct value.\n";
						cout << "Options:";
						cin >> mchoice;//it will loop until input is correct
					}
					switch(mchoice)
					{
						case'1':
							{
								cout<<"Anagram of word "<<search<< " are...\n";
								l.display2(search);//displays all anagrams of the word
								system("PAUSE");
								break;
							}
						case'2':
							{
								int acheck=1;
								string alpha;
								cout<<"Enter one of the letters in the searched word: ";
								cin>>alpha;//one of the searched word letter
								for (int i = 0; i < search.length(); i++) { if (alpha[0]==search[i]) { acheck = 0; } }//loop to check wheter the alphabet entered is one of the letters in the word.
								while (acheck != 0)//input validation for alphabets
								{
									//will looop until the alphabet entered is one of the alphabets in the word
									cout << "Error!!!The letter that you entered does not exist in the word you are searching.\n";
									cout << "Enter the correct alphabets: ";
									cin >> alpha;
									for (int i = 0; i < search.length(); i++) { if (alpha[0]==search[i]) { acheck = 0; } }
								}
								l.display3(search,alpha);
								system("PAUSE");
								break;
							}
						case'3':
							{
								cout<<"\nUpdate word.\n\n";
								cout<<"Replace the word "<<search<<" with........\nEnter new word:";
								cin>>nword; //word that will replace the searched word
								l.validatelist(nword, check2);//check whether the word entred is in the link list
								while (check2 == 1)
								{
									//it will loop until the word entered by user does not exist in the main link list 
									//this is to avoid duplicates
									check2 = 0;
									cout << "Error!!!The word alraedy exist in the list.\n";
									cout << "Enter new word: ";
									cin >> nword;
									l.validatelist(nword, check2);
								}
								l.insert(nword, search);//function to insert word after the word we want to edit
								l.deleteNode(search);//function to delete the word user want to delete
								cout << "The word " << search << " has been replaced to " << nword << endl;
								anagram(nword, l, s, q);//function to generate anagrams
								cout<<"\nIts anagrams are....\n";
								l.display2(nword);
								system("PAUSE");
								search = nword;
								break;
							}
						case'4':
							{
								cout<<"Adding word after the word "<<search<<".\n";
								cout<<"Enter the word you want to add: ";
								cin>>nword; //word that will be inserted after the searched word
								l.validatelist(nword, check2);//check whether the word entred is in the link list
								while (check2 == 1)
								{
									//it will loop until the word entered by user does not exist in the main link list 
									//this is to avoid duplicates
									check2 = 0;
									cout << "Error!!!The word alraedy exist in the list.\n";
									cout << "Enter new word: ";
									cin >> nword;
									l.validatelist(nword, check2);
								}
								l.insert(nword, search);//function to insert a word after the searched word
								anagram(nword, l, s, q);//creating the inserted words anagrams
								cout<<"\nWord "<<nword<<" has been added after the word "<<search<<".\n";
								cout<<"\nIts anagrams are....\n";
								l.display2(nword);
								system("PAUSE");
								break;
							}
						case'5':
							{
								cout<<"Deleting word....\n";
								l.deleteNode(search);//function to delete the word entered by user
								menu=0;
								system("PAUSE");
								break;
							}
						case'6':
							{
								menu=0;
								break;
							}
					}
				}
				break;
			}
			case'3':
			{//appending word to list option
				int check3=0;
				cout<<"\nAppending words to list.......\n";
				cout << "\nHow many new words are you going to append?\nQuantity: ";
				cin >> qty; //quantity of word that we want to add
				while (qty < 0)//input validation for qty
				{
					cout << "Input the correct value.\n";
					cout << "Options:";
					cin >> qty;//it will loop until input is correct
				}
				cout << endl;
				for (int i = 0; i < qty; i++)
				{
					cout << "Word : ";
					cin >> appending;//word that we want to append to end of main list
					l.validatelist(appending, check3);//check whether the word entred is in the link list
					while (check3 == 1)
					{
						//it will loop until the word entered by user does not exist in the main link list 
						//this is to avoid duplicates
						check3 = 0;
						cout << "Error!!!The word alraedy exist in the list.\n";
						cout << "Enter new word: ";
						cin >> appending;
						l.validatelist(appending, check3);
					}
					l.append(appending);//appends new word to the main link list
					anagram(appending, l, s, q);//creates new words anagrams
					l.display2(appending);//displays new words anagrams
					system("PAUSE");
					system("CLS");
				}
				break;			
			}
			case'4':
			{
				string all;
				cout<<"\nDisplaying all anagrams of all word in list.......\n";
				l.displayana();//function to display all words of  with thier anagrams
				system("PAUSE");
				system("CLS");
				break;
			}
			case'5':
			{
				//option in the main menu to exit the whole program.
				system("CLS");//clearing command prompt
				cout << "\nThank you for using the program\n\n";
				cout << "Closing program.....\n\n\n";
				system("PAUSE");
				begin=0;
			}
		 }
	}
	return 0;
}

 
void anagram(string word,Linklist<string> & l,stack<string> s,queue<string> q)
{
	//this function is to generate anagrams of a word
	//the method used is swapping method
	//how the function works is
	/*lets say we have word "abcd" this method will swap all characters "a","b","c","d" in each position of the word "abcd"*/
	//when a position in the word is swapped , swapping will happen in the second position while the first position character will be fixed
	//lets say in the first position of the word "abcd" we swap b , then in the position b it will be swapped to a creating anagram "bacd"
	//each time swapping happens the character we are swapping with must not be as same as the characters in the position that we already swap
	//swapping will not occur in the last character of the word
	//so swapping will happen length of the word-1 times (if 4 charcters long means swap will happen 3 timess)
	
	//stack and queue is used in the generation of anagram
	//when the word is send to the anagram function it will be enqueued to the queue
	//then when swapping happen in first postion the word will be dequeued and anagram is generated and pushed to stack
	//after that for the second position words will be poped from satck one by one and the created anagram will be enqueue to queue
	//for the third time queue will be used again 
	//this will happen until the swapping happens in all the position until the position before last character in the word.
	//anagrams generated at the last swapping are the final complete anagrams of the word.
	
	char temp;
	string w,wrd,traverse=word;
	w = word; //w is the variable that will hold each character of word, changing depending on the for loop for swapping
	int length,num=0,counter=0,check=0,output=0;
	length = word.length();
   	q.enqueue(word);

	for (int i = 0; i < length - 1; i++)//this for loop is for the position of the word.
	{
		if (s.isempty()) { num = 1; }//to check whether to use stack or queue
		else if (q.isempty()) { num = 2; }

		if (num == 1) //using queue
		{
			while (!q.isempty())//until queue is empty
			{
				output = 1;
				q.dequeue(word);
				for (int x = 0; x < length; x++)//for loop for each characters in a word
				{
					temp = w[x];
					wrd = word;
					for (int z = 0; z < length; z++)//for loop for searching the position of the character that used to swap in the word before swapping
					{
						if ((w[x] == wrd[z]) && counter==0)//for first swapping
						{
							wrd[z] = wrd[i];
							wrd[i] = temp;
							s.push(wrd);
						}
						if ((w[x] == wrd[z]) && counter==1) //for the rest of the swapping
						{
							for (int u = 0; u < i; u++) // to check whether the characted used for swapping is same as the characters in the position where swapping already occured
							{
								if (wrd[u] != w[x])
								{
									check = 1;
								}
								else if (wrd[u] == w[x])
								{
									check = 0;
									break;
								}
							}
							if (check == 1) //swapping process
							{
								wrd[z] = wrd[i]; 
								wrd[i] = temp;
								s.push(wrd);//pushing the generated anagram to stack
							}
							check = 0;
						}
					}
				}
			}
		}
		else if (num == 2)//using stack
		{
			while (!s.isempty()) //until stack is empty
			{
				output = 2;
				s.pop(word); //popping the word from stack
				for (int x = 0; x < length; x++)//for loop for each characters in a word
				{
					temp = w[x];
					wrd = word;
					for (int z = 0; z < length; z++)//for loop for searching the position of the character that used to swap in the word before swapping
					{
						if (w[x] == wrd[z])
						{
							for(int u = 0; u < i; u++)// to check whether the characted used for swapping is same as the characters in the position where swapping already occured
							{
								if (wrd[u] != w[x])
								{
									check = 1;
								}
								else if (wrd[u] == w[x])
								{
									check = 0;
									break;
								}
							}
							if (check == 1)//swapping process
							{
								wrd[z] = wrd[i];
								wrd[i] = temp;
								q.enqueue(wrd);//enqueuing word to queue
							}
							check = 0;
						}
					}
				}
			}
		}
		num = 0;
		counter = 1;
	}

    //after all the anagrams has been genereted it checks where is the anagrams in , in the stack or queue
	if (output == 1)
	{
		while (!s.isempty())
		{
			s.pop(wrd);
			l.append2(wrd,traverse);//appending the generated anagrams to the permute pointer for each word in the main link list 
		}
	}
	else if (output == 2)
	{
		while (!q.isempty())
		{
			q.dequeue(wrd);
			l.append2(wrd,traverse);//appending the generated anagrams to the permute pointer for each word in the main link list
		}
	}
}
