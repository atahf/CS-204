/*************************************
*Modified by Gizem Gezici
*Date: 05.03.2012
*************************************/

#include <iostream>
#include "linkedList.h"

using namespace std;

linkedlist::linkedlist()
{
	head=NULL;
}

void linkedlist::printList()
{
    if (head != NULL)
    {
        cout << head->data << endl;
        node * ptr = head->next;
        while(ptr != head)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}

void linkedlist::addToBeginning(string n)
{
	if(head == NULL)
	{
		node *ptr = new node(n, head);
		head = ptr;
		head->next = head;
	}
	else
	{
		node *oldhead = head;
		node *ptr = new node(n, head);
		head = ptr;
		node* itr= oldhead;
		while(itr->next != oldhead)
		{
			itr = itr->next;
		}
		itr->next = head;
	}
}

/*****************
Delete Function could be implemented here.
******************/

void linkedlist::printListInverse()
{
    if (head != NULL)
        printListInverse(head);
    else
        cout << "List is empty" << endl;
}


void linkedlist::printListInverse(node *n)
{
	if(n->next != head)
	{
		printListInverse(n->next);
	}
	cout << n->data << endl;
}