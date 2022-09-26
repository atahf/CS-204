#include <iostream>
#include <stdlib.h>
#include "TemplatedQueue.h"
#include "Person.h"
using namespace std;


template <class T>
void Print(Queue<T> myQueue)
{
	if(myQueue.isEmpty())
	{
		cout << "Queue is empty!\n";
		return;
	}
	T value;

	while(!myQueue.isEmpty())
	{
		myQueue.dequeue(value);
		cout << value << " ";
	}
	cout << endl;
}

int main()
{
	Queue<int> intQueue;
	Person<int> intCashier(intQueue);
	Person<int> intCustomer(intQueue);
	int intItems[10] = {23, 54, 15, 9, 56, 78, 93, 101, 921, 234};
	
	for (int i = 0; i < 10; i++)
	{
		intCustomer.put(intItems[i]);
	}
	cout<<"intCustomer bought 10 different int items, current intQueue:\n";
	Print(intQueue);

	int intTemp;
	for (int i = 0; i < 10; i++)
	{
		intCashier.take(intTemp);
	}
	cout<<"After intCashier check-out process, current intQueue:\n"; 
	Print(intQueue);

	cout<<endl;

	Queue<char> charQueue;
	Person<char> charCashier(charQueue);
	Person<char> charCustomer(charQueue);
	char charItems[10] = {'z', 'd', 'g', 'h','a','t','b','k','s','f'};

	for (int i = 0; i < 10; i++)
	{
		charCustomer.put(charItems[i]);
	}
	cout<<"charCustomer bought 10 different char items, current charQueue:\n";
	Print(charQueue);

	char charTemp;
	for (int i = 0; i < 10; i++)
	{
		charCashier.take(charTemp);
	}
	cout<<"After charCashier check-out process, current charQueue:\n"; 
	Print(charQueue);

	return 0;
}