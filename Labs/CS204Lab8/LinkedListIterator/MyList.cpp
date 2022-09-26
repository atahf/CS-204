/*
Modified by Gizem Gezici
Modified Date: 10.04.2012
Linked List Iterator

*/

#include "MyList.h"

//START of
//definitions of methods of class MyList

//Default Constructor
MyList::MyList()
{
	head = NULL;
	tail = NULL;
	numItems = 0;
}

//Constructor with parameters
//initializes the object with parameter 'num' strings
MyList::MyList(string* list,int num)
{
	head = NULL;
	tail = NULL;
	numItems = 0;
	for(int i=0; i < num; i++)
	{
		addToEnd(list[i]);
	}

}

//Implemented by Gizem Gezici
void MyList::addToEnd(string &newData)
{
	Node *ptr = head;

	//List is empty
	if(tail == NULL)
	{
		Node *temp = new Node(newData, NULL, NULL);
		tail = temp;
		head = tail;
	}
	else
	{
		Node *temp = new Node(newData, NULL, tail);
		tail->next = temp;
		tail = temp;
	}
	numItems++;
}

//Implemented by Gizem Gezici
void MyList::addToBeginning(string &newData)
{
	//List is empty
	if(head == NULL)
	{
		Node *ptr = new Node(newData, NULL, NULL);
		head = ptr;
		tail = head;	
	}
	else
	{
		Node *ptr = new Node(newData, head, NULL);
		head->previous = ptr;
		head = ptr;
	}
}

int MyList::numberOfElements()
{
	return numItems;
}

//END of
//definitions of methods of class MyList


//START of
//definitions of methods of class MyListItr, the iterator class

//constructor of class MyListItr
MyListItr::MyListItr(const MyList &l): 
	list(l),current(NULL)
{
}

//Modified by Gizem Gezici
//pre-condition: The list has more elements after 'current' to traverse
void MyListItr::next()
{
	current = current->next;
}

//Modified by Gizem Gezici
//pre-condition: The list has more elements before 'current' to traverse
void MyListItr::previous()
{
	current = current->previous;
}

//Implemented by Gizem Gezici
bool MyListItr::hasMore()
{
	if(current != NULL)
		return false;
	return true;
}

//Get the string data in the linked list node.
//pre-condition: The 'current' element must not be NULL
//since the return type is reference, the changes to the returned variable
//will be done on the actual variable in the linked list
string & MyListItr::Data()
{
	return current->data;
}

//Go to the beginning of the linked list.
void MyListItr::goToBeginning()
{
	current = list.head;
}

//Go to the end of the linked list.
void MyListItr::goToEnd()
{
	current = list.tail;
}

//END of
//definitions of methods of class MyListItr, the iterator class