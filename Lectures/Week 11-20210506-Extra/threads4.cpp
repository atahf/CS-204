#include <iostream>
#include <thread>
using namespace std;

//create aThread as a global object to exemplify the case to join a thread within its entry function
// thread aThread;

void hello() 
{
  cout << "Hello thread\n";

  //to join aThread within itself uncomment the following - will crash
  // aThread.join();

  //to exemplify the case where joinable cannot be called for aThread in itself uncomment following
  //if (aThread.joinable()) 
  //	aThread.join();
}

int main() 
{
  thread aThread(&hello);
 
  /*create aThread as a default constructed one to see calling 
  join/detach on an uninitialized thread causes the program to crash*/
  //thread aThread;

  //for joining in itself test, uncomment the following with athread defined as global and comment out the above definition
  //aThread = thread(&hello);

  aThread.join();
  //aThread.detach(); //repeat the test below with detach as well
  cout << "Bye main\n";
  
  /*uncomment the following line to see calling join on an 
  already joined/detached thread causes the program to crash*/
  //aThread.join(); 
  
  /*check that the above problem does not occur if you check if aThread 
  is joinable before joining*/
  //if (aThread.joinable()) 
  //	aThread.join();

  return 0; 
}