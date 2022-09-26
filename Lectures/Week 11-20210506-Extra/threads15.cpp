#include <thread>
#include <iostream>
#include <mutex>  //to use mutex
using namespace std;

#define THREADS_NUM 2

mutex myMutex;

void increment(int & value)
{
	for (int i=0; i <1000000; i++)
	{
		myMutex.lock();
		value++;
		myMutex.unlock();
	}
}

int main()
{
  int i;
  int counter = 0;
  cout << "At the beginning of main counter is: " << counter << endl;
  thread threads[THREADS_NUM];
  for (i=0; i < THREADS_NUM; i++)
  {
      threads[i] = thread(&increment, ref(counter));  //use ref() if the corresponding parameter is reference
	  //threads[i] = thread(&increment, counter); //this does not work is intended. value is not passed as reference
  }

  for (i=0; i < THREADS_NUM; i++)
  {
      threads[i].join();
  }
  cout << "At the end of main counter is: " << counter << endl;
  return 0;
}