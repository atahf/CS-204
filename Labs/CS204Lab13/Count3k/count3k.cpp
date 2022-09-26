/* author : kamer
edited by: albert levi, ertunc erdil
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
mutex m;
int counter = 0, ctr = 0;
int maximum = 100000;

void count() {
	/*
	CASE 1
	comment out line A
	comment out line B
	comment out line C

	CASE 2
	uncomment line A
	uncomment line B
	comment out line C

	CASE 3
	uncomment line A
	uncomment line B
	uncomment line C
	*/
	while(counter < maximum) 
	{ 
		counter++;
		m.lock(); //LINE A
		ctr++;
		m.unlock(); //LINE B
		this_thread::sleep_for(chrono::microseconds(1)); //LINE C
	}
}

int main()  {
	thread thr[6];

	for(int i = 0; i < 6; i++)
	{
		thr[i] = thread (&count);
	}

	for(int i = 0; i < 6; i++)
	{
		thr[i].join();
	}

	cout <<"Loop iteration count: " <<ctr <<endl;
	cout <<"Counter value: "<< counter << endl;
	
	return 0;    
}