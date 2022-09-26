/*Author: Zeynep Dogmus
 *Date: March 2013
 *Operator Overloading with Queue
*/
#include <iostream>
#include "DynamicStringQueue.h"

using namespace std;


//Passing the parameter as a value parameter: will invoke Copy Constructor & Destructor
//Normally, we pass class parameters as const reference or reference, but here we had to pass as
//value parameter because we do not want to clear content of the queue.
void Print(DynamicStringQueue myQueue)
{
	string value = "";
	
	#ifdef _DEBUG
		cout << "Printing the queue..." << endl;
	#endif
	
	while(!myQueue.isEmpty())
	{
		myQueue.dequeue(value);
		cout << value << "\n";
	}
	cout << endl;
}


int main()
 {
	DynamicStringQueue queue = DynamicStringQueue();
	DynamicStringQueue queue2 = DynamicStringQueue();
	DynamicStringQueue result = DynamicStringQueue();
	int value;
	string tmp = "";

	queue.enqueue("Ali");
	queue.enqueue("Veli");
	queue.enqueue("Kemal");
	cout << "Queue 1: " << endl;

	#if defined(SCENARIO3) || defined(SCENARIO4) || defined(SCENARIO5) || defined(SCENARIO6)
		Print(queue);
	#endif
	queue2.enqueue("Derya");
	queue2.enqueue("Ayse");
	queue2.enqueue("Asli");
	cout << "Queue 2: " << endl;

	#if defined(SCENARIO3) || defined(SCENARIO4) || defined(SCENARIO5) || defined(SCENARIO6)
		Print(queue2);
	#endif
	cout << "**************************************************************" << endl;
	
	queue2 = queue;
	DynamicStringQueue queue3(queue);
	cout << "queue2 = queue is done (= operator example)" << endl;
	cout << "Queue 1: " << endl;
	#if defined(SCENARIO3) || defined(SCENARIO4) || defined(SCENARIO5) || defined(SCENARIO6)
		Print(queue);
	#endif
	cout << "Queue 2: " << endl;
	#if defined(SCENARIO3) || defined(SCENARIO4) || defined(SCENARIO5) || defined(SCENARIO6)
		Print(queue2);
	#endif
	cout << "**************************************************************" << endl;

	queue.enqueue("Ozge");
	queue2.enqueue("Selcuk");
	cout << "Queue 1: " << endl;
	#if defined(SCENARIO3) || defined(SCENARIO4) || defined(SCENARIO5) || defined(SCENARIO6)
		Print(queue);
	#endif
	cout << "Queue 2: " << endl;
	#if defined(SCENARIO3) || defined(SCENARIO4) || defined(SCENARIO5) || defined(SCENARIO6)
		Print(queue2);
	#endif


	cout << "**************************************************************" << endl;

	//system("pause");
	
	return 0;
}