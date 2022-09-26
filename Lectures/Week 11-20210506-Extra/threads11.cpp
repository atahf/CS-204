#include <thread>
#include <iostream>
#include <mutex>  //to use mutex
using namespace std;

int value = 0;
#define THREADS_NUM 2

mutex myMutex;

void increment()
{
	for (int i=0; i <1000000; i++)
	{
		myMutex.lock();
		
		//if an already locked mutex is tried to be locked by the same thread, then your program either crashes or behaves unexpectedly 
			//(different behaviors can be seen in debug and release mode)
		//myMutex.lock();
		
		value++;
		
		myMutex.unlock();
		
		//if an unlocked mutex is unlocked again before locking it, then your program either crashes or behaves unexpectedly 
			//(different behaviors can be seen in debug and release mode)
		//myMutex.unlock();
	}
}

int main()
{
  //if a mutex is unlocked before locking it, then your program either crashes or behaves unexpectedly 
			//(different behaviors can be seen in debug and release mode)
  //myMutex.unlock();

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
  return 0;
}