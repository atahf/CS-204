/*
Modified by Gizem Gezici
Modified Date: 10.04.2012
Linked List Iterator

*/

#include "MyList.h"
#include <iostream>
using namespace std;

//Print the list 
void PrintForward(MyList & lst)
{
	MyListItr itr(lst);
	cout << "Printing the list..." << endl;
	itr.goToBeginning();
	while(!itr.hasMore())
	{
		cout << itr.Data() << " ";
		//Since we're printing forward
		itr.next();
	}
	cout << endl;
	cout << endl;
}

//Print the list in reverse order
void PrintBackward(MyList & lst)
{
	MyListItr itr(lst);
	cout << "Printing the list in reverse order ..." << endl;
	itr.goToEnd();
	while(!itr.hasMore())
	{
		cout << itr.Data() << " ";
		//Since we're printing backward
		itr.previous();
	}
	cout << endl;
	cout << endl;
}

//set the first character of the elements of the 'lst' to 'chr'
void setFirstCharacter(MyList & lst, char ch)
{
	MyListItr itr(lst);
	itr.goToBeginning();
	string temp;

	while(!itr.hasMore())
	{
		temp = itr.Data();
		itr.Data() = ch + temp.substr(1, temp.length());
		itr.next();
	}
}


void main()
{
	int numElements = 0;
	string* dataList;

	cout << "Enter number of elements :" ;
	cin >> numElements;

	dataList = new string[numElements];

	//Get the input from the keyboard (string elements) in order to create the list
	for(int i=0; i < numElements; i++)
	{
		cout << "Enter element :";
		cin >> dataList[i];
	}
	
	cout << endl;

	//Create the list with the entered elements from the keyboard
	MyList myList(dataList,numElements);
	PrintForward(myList);
	PrintBackward(myList);

	string s = "LastElement";
	string s1 = "FirstElement";

	myList.addToBeginning(s1);
	myList.addToEnd(s);

	PrintForward(myList);
	PrintBackward(myList);

	//1 - change the original array
	//let us pad "xyz" to the end of every element of the array
	for (int i = 0; i < numElements; i++)
		dataList[i] += "xyz";

	//print the linked list, see the change
	PrintForward(myList);

	//2 - change the list with the iterator
	//let us set the first character of every element of the linked list to '0'
	setFirstCharacter(myList, '0');

	//print the linked list, see the change
	PrintForward(myList);

	//print the array, see the change
	cout << "Printing the array" << endl;
	for (int i = 0; i < numElements; i++)
		cout << dataList[i] << " ";

	cout << endl;

	cin.ignore();
	cin.get();
	return;
}