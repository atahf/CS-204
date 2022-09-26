/*
Modified by Gizem Gezici
Modified Date: 18.04.2012
Templated LinkedList and LinkedListIterator Tapestry Codes

*/

#include <iostream>
#include <string>
using namespace std;
#include "linkset.h"

// demo of string sets implemented with linked lists

template <class T>
void Print(const LinkSet<T>& set)
{
	//Templated LinkedListIterator 
    LinkSetIterator<T> it(set);
    for(it.Init(); it.HasMore(); it.Next())
    {   
		cout << "\t" << it.Current() << endl;
    }
    cout  << "---------- size = " << set.size() << endl;
}

int main()
{
    LinkSet<string> a,b;
    
    a.insert("apple");
    a.insert("cherry");
	a.insert("orange");
    cout << "a : "; Print(a);
    b = a;
    cout << "b : "; Print(b);
    a.clear();
    cout << "a : "; Print(a);
    cout << "b : "; Print(b);

	LinkSet<int> myList;

	myList.insert(3);
	myList.insert(5);
	myList.insert(7);

	cout << "mylist: " << endl;
	Print(myList);

	cin.ignore();
	cin.get();
    return 0;
}
