#include <thread>
#include <iostream>
#include <mutex>  //to use mutex
using namespace std;

int value = 0;
#define THREADS_NUM 2

mutex myMutex;

void increment()
{
	int unsuccessfulLock = 0;
	for (int i=0; i <10000; i++)
	{
		bool isLocked;
		isLocked = myMutex.try_lock();
		if (isLocked)
		{
			value++;		
			myMutex.unlock();
		}
		else
		{
			unsuccessfulLock++;
		}
	}
	cout << "Unsuccessful Lock: " << unsuccessfulLock << endl;
}

int main()
{
  int i;
  cout << "At the beginning of main value is: " << value << endl;
  thread threads[THREADS_NUM];
  for (i=0; i < THREADS_NUM; i++)
  {
      threads[i] = thread(&increment);
  }

  for (i=0; i < THREADS_NUM; i++)
  {
      threads[i].join();
  }
  cout << "At the end of main value is: " << value << endl;  
  //What is your expectation about the values of "value", and "unsuccessfullock" variables of the threads?
  return 0;
}