/***************************************************
This program demonstrates the use of static local variables. 
It includes a magicalFunction() in which a static local variable 
is declared. Because of the static keyword, the lifetime of 
the variable becomes the entire execution of the program. 
When this function is called again and again, this variable 
will still have the value it had when execution last left the 
function. 

Author: Zeynep Dogmus
Date: Feb. 2013
****************************************************/
#include <iostream>
#include <string>

using namespace std;

//This function preserves the value of staticLocalString 
void magicalFunction()
{
	static string staticLocalString= "First value assigned. ";
	cout << staticLocalString << endl;
	staticLocalString +="Updated in function. ";	
	cout << staticLocalString << endl;
}

int main()
{
	/*Call magicalFunction (at least) twice for static local variable example */
	cout << "First call." << endl;
	magicalFunction();
	cout << "Second call." << endl;
	magicalFunction();
	//cout << "Third call." << endl;
	//magicalFunction();
	system("pause");
	return 0;
}