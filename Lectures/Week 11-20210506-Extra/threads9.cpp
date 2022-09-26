#include <thread>
#include <iostream>
#include <sstream>
using namespace std;

void hello(int order)
{
	for (int i= 1; i<=20; i++)
	{
		ostringstream display;
		display << "\tHello " << order << " " <<  this_thread::get_id() << " " << i << endl;  
		cout << display.str();
			//here we first prepared the string to be displayed. Then we cout it directly. This reduces the chance of scheduling in the middle of a cout. 
	}
}

int main()
{
  int i;
  thread myThread;
  for (i=0; i < 5; i++)
  {
      myThread = thread(&hello,i);

	  for (int j= 1; j<=10; j++)
	  {
		 ostringstream display;
		 display << "Hello main " << j << endl;  
		 cout << display.str(); 
	  }
	  /* a thread object can be re-initilaized after you are done with it via join or detach. 
		 If you re-initialize a thread object without join or detach, your program eventually crashes.
		 Try this by commenting out the following two lines. 

		 Moreover, if you use detach here, you have to sleep the main thread for a couple of milliseconds in order to see all the output. 
		 Otherwise, the main thread may end before myThread instances; this does not cause a crash, but some of the outputs of the myThread instances may become invisible.

		 Another interesting point here is that if you use join, the myThread instances start and end consecutively; thus their outputs do not mixup.
		 However, if you use detach, more than one myThread instances may be active at a given time; thus, their outputs may interleave. Try this!
		 */

		myThread.join();
		//myThread.detach();
  }
  //this_thread::sleep_for(chrono::milliseconds(100));  //use this for detach to make sure that you see all outputs before main ends. Comment this line to potentially see partial output.
  return 0;
}