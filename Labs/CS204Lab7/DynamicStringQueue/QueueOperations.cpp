/*Author: Zeynep Dogmus
 *Date: March 2013
 *Operator Overloading with Queue
*/
#include <iostream>
#include "DynamicStringQueue.h"

using namespace std;

//******************************************************
// Add operator returns queue1 + queue2 as a new queue *
// without modifying the queues passed as parameter    *
//******************************************************
DynamicStringQueue operator+(const DynamicStringQueue &  queue1, const DynamicStringQueue &  queue2)
{
	DynamicStringQueue result;
	DynamicStringQueue myFirstQueue(queue1);
	DynamicStringQueue mySecondQueue(queue2);
	string value;

	while(!myFirstQueue.isEmpty())
	{
		myFirstQueue.dequeue(value);
		result.enqueue(value);
	}
	while(!mySecondQueue.isEmpty())
	{
		mySecondQueue.dequeue(value);
		result.enqueue(value);
	}

	return result;
}

//****************************************************************
// Enqueue the values of rhs queue to the end of the lhs queue   *
// by modifying only the lhs queue (not rhs queue)               *
//****************************************************************
const DynamicStringQueue & operator+=(DynamicStringQueue &  lhs, const DynamicStringQueue & rhs)
{
	//copy constructor
	DynamicStringQueue rhsQueue(rhs);

	//After calling copy constructor, print the queues in order to compare them.
	/*Print(rhs);
	Print(rhsQueue);*/
	string value;

	while(!rhsQueue.isEmpty())
	{
		rhsQueue.dequeue(value);
		lhs.enqueue(value);
	}
	return lhs;
}

//Passing the parameter as a value parameter: Copy Constructor & Destructor
void Print(DynamicStringQueue myQueue)
{
	string value = "";
	
	#ifdef _DEBUG
		cout << "Printing the queue..." << endl;
	#endif
	
	while(!myQueue.isEmpty())
	{
		myQueue.dequeue(value);
		cout << value << " ";
	}
	cout << endl;
}

int main()
{
	DynamicStringQueue queue = DynamicStringQueue();
	DynamicStringQueue queue2 = DynamicStringQueue();
	DynamicStringQueue result = DynamicStringQueue();
	int value;

	queue.enqueue("Ali");
	queue.enqueue("Veli");
	queue.enqueue("Kemal");
	cout << "Queue 1: " << endl;
	Print(queue);

	queue2.enqueue("Derya");
	queue2.enqueue("Ayse");
	queue2.enqueue("Asli");
	cout << "Queue 2: " << endl;
	Print(queue2);
	cout << "**************************************************************" << endl;
	
	result = queue + queue2;
	cout << "result = queue + queue2 is done (+ operator example)" << endl; 
	cout << "Result: " << endl;
	Print(result);
	cout << "**************************************************************" << endl;

	queue += queue2;
	cout << "queue += queue2 is done (+= operator example)" << endl;
	cout << "Queue 1: " << endl;
	Print(queue);
	cout << "Queue 2: " << endl;
	Print(queue2);
	cout << "**************************************************************" << endl;
	
	queue += queue2 += queue;
	cout << "queue += queue2 += queue is done (+= operator example)" << endl;
	cout << "Queue 1: " << endl;
	Print(queue);
	cout << "Queue 2: " << endl;
	Print(queue2);
	cout << "**************************************************************" << endl;

	queue2 = queue;
	cout << "queue2 = queue is done (= operator example)" << endl;
	cout << "Queue 1: " << endl;
	Print(queue);
	cout << "Queue 2: " << endl;
	Print(queue2);
	cout << "**************************************************************" << endl;

	cout << "Please enter a value to compare the size of queue 2 (for the < operator example): ";
	cin >> value;

	if(queue2 < value)
	{
		cout << "Number of elements inside the queue is smaller than " << value << "!" << endl;
	}
	else
		cout << "Number of elements inside the queue is greater than " << value << "!" << endl;


	//system("pause");
	
	return 0;
}