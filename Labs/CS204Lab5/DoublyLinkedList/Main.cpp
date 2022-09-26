/*Author: Gizem Gezici
  Date: 12.03.2012
  Doubly Linked List
  Program Run: In order to see the different effects between print and printReverse 
  as well as add to beginning and add to end member functions, you can write the 
  same sentence! For example, the sentence could be:
  *****CS204 is a very enjoyable course!*****
  Have fun!:)
*/


#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;


int main()
{
	linkedlist myDoublyLinkedList;
	string word = "";

	cout << "Dear user, please enter some words. If you would like to stop writing words" << endl;
	cout << "then please press Ctrl-Z" << endl;
	while(cin >> word)
	{
		myDoublyLinkedList.addToBeginning(word);
	}

	//Since we are adding words at the beginning of the list
	//Print the list
	//The last added word will be displayed first
	myDoublyLinkedList.printList();
	cout << endl;
	//Print the list in a reverse order
	//The last added word will be displayed last
	myDoublyLinkedList.printListInverse();

	//Clear the linked list.
	myDoublyLinkedList = linkedlist();

	cin.clear();
	cout << "Dear user, please enter some words. If you would like to stop writing words" << endl;
	cout << "then please press Ctrl-Z" << endl;
	while(cin >> word)
	{
		//Difference with above
		myDoublyLinkedList.addToEnd(word);
	}

	//Since we are adding words at the end of the list
	//Print the list
	//The last added word will be displayed last
	myDoublyLinkedList.printList();
	cout << endl;

	//Print the list in a reverse order
	//The last added word will be displayed first
	myDoublyLinkedList.printListInverse();

	/*****************
	You may implement a delete function for this linked list
	******************/


	system("pause");
	return 0;
}