#include <thread>
#include <iostream>
#include <mutex>
#include "randgen.h"
#include <random>
#include <time.h>
using namespace std;

mutex coutMutex;

RandGen r;
#define THREADS_NUM 2

int random_range(const int & min, const int & max) 
{
    static mt19937 generator(time(0));
    uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}

void listRandomNumbers(int order)
{
	for (int i=0; i <10; i++)
	{
		coutMutex.lock();
		//cout << "Thread " << order << ": " << r.RandInt(1,10) << endl;  //if you create the random number using RandGen all threads create the same random number sequence. This is not what we want
		cout << "Thread " << order << ": " << random_range(1,10) << endl; //if you use this function, all threads generate different random number sequences as intended 
		coutMutex.unlock();
	}
}


int main()
{
  int i;

  thread threads[THREADS_NUM];
  for (i=0; i < THREADS_NUM; i++)
  {
      threads[i] = thread(&listRandomNumbers,i);
  }

  for (i=0; i < THREADS_NUM; i++)
  {
      threads[i].join();
  }

  return 0;
}