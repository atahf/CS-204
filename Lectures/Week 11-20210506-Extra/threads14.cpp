#include <thread>
#include <iostream>
#include <mutex>  //to use mutex
using namespace std;

mutex myMutex1, myMutex2;

void thread_func1()
{
	myMutex1.lock();
	cout << "thread1, first mutex locked\n";
	myMutex2.lock();
	cout << "thread1, second mutex locked\n";
	
	myMutex2.unlock();
	cout << "thread1, second mutex unlocked\n";
	myMutex1.unlock();
	cout << "thread1, first mutex unlocked\n";
}

void thread_func2()
{
	myMutex2.lock();
	cout << "thread2, second mutex locked\n";
	myMutex1.lock();
	cout << "thread2, first mutex locked\n";

	myMutex1.unlock();
	cout << "thread2, first mutex unlocked\n";	
	myMutex2.unlock();
	cout << "thread2, second mutex unlocked\n";
}

//The functions above cause deadlock since they wait for each other.
//Solution is to lock the mutexes in the same order in both function. See below.
/*void thread_func2()
{
	myMutex1.lock();
	cout << "thread2, first mutex locked\n";
	myMutex2.lock();
	cout << "thread2, second mutex locked\n";

	myMutex2.unlock();
	cout << "thread2, second mutex unlocked\n";
	myMutex1.unlock();
	cout << "thread2, first mutex unlocked\n";	
}*/



int main()
{
	thread thread1(&thread_func1);
	thread thread2(&thread_func2);
	thread1.join();
	thread2.join();
	return 0;
}