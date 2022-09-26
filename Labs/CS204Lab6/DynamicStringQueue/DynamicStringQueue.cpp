/*Author: Zeynep Dogmus
 *Date: March 2013
 *Operator Overloading with Queue
*/
#include <iostream>
#include "DynamicStringQueue.h"
using namespace std;

//********************************************
// Constructor. Generates an empty queue     *
//********************************************
DynamicStringQueue::DynamicStringQueue()
{
	front = NULL;
	rear = NULL;
}

QueueNode* DynamicStringQueue::GetFront()
{
	return front;
}

QueueNode* DynamicStringQueue::GetRear()
{
	return rear;
}

//********************************************
// Deep Copy Constructor                     *
//********************************************

#if defined(SCENARIO1) || defined(SCENARIO3) || defined(SCENARIO5) || defined(SCENARIO6)
DynamicStringQueue::DynamicStringQueue(const DynamicStringQueue & copy)
{
	createClone(copy);
	#ifdef _DEBUG
		cout << "Deep copy constructor is invoked\n";
		cout << endl;
	#endif
}
#endif

//******************************************************************
// Shallow Copy Constructor:									   *
// Queue that is copied with a shallow copy will be problematic.   *
// Since it only copies the front and rear of the original queue.  *
// Copied queue will be modified as the original queue is modified.*
//******************************************************************
#if defined(SCENARIO2) || defined(SCENARIO4)
DynamicStringQueue::DynamicStringQueue(const DynamicStringQueue & q)
{
#ifdef _DEBUG
	cout << "Shallow copy constructor is invoked\n";
	cout << endl;
#endif
	front = q.front;	//front copy
	rear = q.rear;		//rear copy
}
#endif

void DynamicStringQueue::createClone(const DynamicStringQueue & copy)
{
	if (copy.front == NULL) 
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		QueueNode * temp = copy.front;
		front = new QueueNode(temp->value, NULL);
		rear = front;

		while(temp->next != NULL) 
		{
			temp = temp->next;
			rear->next = new QueueNode(temp->value, NULL);
			rear = rear->next;
		}
	}
}

//****************************************************
// Assignment operator                               *                                    
//****************************************************
#if defined(SCENARIO1) || defined(SCENARIO2) || defined(SCENARIO3) || defined(SCENARIO4) || defined(SCENARIO5)
const DynamicStringQueue & DynamicStringQueue::operator=(const DynamicStringQueue & rhs)
{
#ifdef _DEBUG
	cout << "Deep assignment operator is invoked\n";
	cout << endl;
#endif
	//Check whether the rhs object is different than our queue
	if (this != &rhs)
	{
		clear(); 
		createClone(rhs);
	}
	return *this;
}
#endif

#if defined(SCENARIO6)
const DynamicStringQueue& DynamicStringQueue::operator=(const DynamicStringQueue& rhs)
{
#ifdef _DEBUG
	cout << "Shallow assignment operator is invoked\n";
	cout << endl;
#endif
	//Check whether the rhs object is different than our queue
	if (this != &rhs)
	{
		clear();
		this->rear = rhs.rear;
		this->front = rhs.front;
	}
	return *this;
}
#endif
//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
void DynamicStringQueue::enqueue(string elmt)
{
	if (isEmpty())   //if the queue is empty
	{	//make it the first element
		front = new QueueNode(elmt);
		rear = front;
	}
	else  //if the queue is not empty
	{	//add it after rear
		rear->next = new QueueNode(elmt);
		rear = rear->next;
	}
	#ifdef _DEBUG
		cout << elmt << " enqueued\n";
	#endif
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
void DynamicStringQueue::dequeue(string &elmt)
{
	QueueNode *temp;
	if (isEmpty())
	{
		cout << "Attempting to dequeue on empty queue, exiting program...\n";
		exit(1);
	}
	else //if the queue is not empty
	{	//return front's value, advance front and delete old front
		elmt = front->value;
		temp = front;
		front = front->next;
		delete temp;      
	}
	#ifdef _DEBUG
		cout << elmt << " dequeued\n";
	#endif
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
bool DynamicStringQueue::isEmpty() const
{
	if (front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************
void DynamicStringQueue::clear(void)
{
	string value;   // Dummy variable for dequeue

	while(!isEmpty())
	{
		dequeue(value); //delete all elements
	}
}

DynamicStringQueue::~DynamicStringQueue()
{
	clear();
	#ifdef _DEBUG
		cout << "Destructor is invoked\n";
		cout << endl;
	#endif
}