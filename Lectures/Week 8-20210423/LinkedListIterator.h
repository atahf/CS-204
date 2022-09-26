#ifndef _LINKEDLISTITERATOR_H
#define _LINKEDLISTITERATOR_H

struct node {
	int info;
	node *next; 

	node ()
	{}

	node (const int & s, node * link)
		: info(s), next (link)
	{}
};

class LinkedList 
{
	//friend class can access private data members of of LinkedList class
	//this friend class line can be added anywhere in this class declaration
	friend class LinkedListIterator;

	private:
		node * head;
		int size;
	public:
		 LinkedList (); 
		 LinkedList (const LinkedList &);  //copy constructor 
		 ~LinkedList ();   //destructor
		 void printList() const;
		 void addToBeginning(int n);
		 void deleteList ();
		 int length() const;  //returns # of elements in the list
		 const LinkedList & operator = (const LinkedList & rhs);
		 node * createClone () const; //generates the clone of the list and return the clone's head
};

//Iterator Class for LinkedList
class LinkedListIterator {
	public:
		LinkedListIterator(const LinkedList & list): myList(list), myCurrent(NULL) {}
		void Init() {myCurrent = myList.head;}
		bool HasMore() const {return (myCurrent != NULL);}
		int Current() const {return myCurrent->info;}
		void Next() {myCurrent = myCurrent->next;}
	private:
		const LinkedList & myList;
		node *  myCurrent;
};


#endif