/***************************************************
globalDemo1 and globalDemo2 together demonstrate the use 
of global, extern and static global variables. The usages 
of these variables are illustrated in four cases. 

CASE 1: 
In this case, we reach and modify the global variable 
globalString by using extern variable. 

CASE 2: 
Case 2 illustrates the case where we have a static global variable, 
having the same name with a static global variable in another module. 
Each staticGlobalString is visible to the module that it is declared in. 

CASE 3:
In this case, we have a static global variable in globalDemo2, and 
we try to reach this variable from here by using an extern variable. 

CASE 4:
This case includes two global variables with the same name in both globalDemo1 
and globalDemo2. We again try to reach the same variable from here 
and from globalDemo2.

Author: Zeynep Dogmus
Date: Feb. 2013
****************************************************/
#include <iostream>
#include <string>

using namespace std;

void updateGlobalString(string newString);
void printGlobalString();
void printStaticGlobalString();
void printStaticGlobalString2();
void printGlobalString2();

extern string globalString;					//Extern variable for case 1

static string staticGlobalString = "My first static global string";	//Static variable for case 2

//extern string staticGlobalString2;		/*Uncomment to get a compiler error (case 3)*/

//string globalString2 = "Globalstring1";		/*Uncomment to get a compiler error (case 4)*/

int main()
{

	/* CASE 1
	This part first prints the default value by calling the 
	function in globalDemo2. Afterwards, it modifies the string 
	using the extern variable, and prints it. Lastly, it modifies 
	this string by calling the updateGlobalString() function of globalDemo2. */

	/*printGlobalString();			//Global string is displayed via the function in its module
	globalString += "Apple ";		//Global string is updated directly
	cout << globalString << endl;
	//Global string is updated via the function in its module
	updateGlobalString("Banana ");	
	cout << globalString << endl;*/

	/**************************************************************/

	/*CASE 2 
	This part prints the static global variables. The variable 
	staticGlobalString declared here is printed first. Then, the 
	variable with the same name declared in globalDemo2	is printed 
	via the function in globalDemo2. */

	/*cout << staticGlobalString << endl;
	printStaticGlobalString();*/

	/**************************************************************/

	/* CASE 3
	This part tries to update the static global variable declared 
	in globalDemo2, using extern variable. Then, it tries to print 
	staticGlobalString2 via extern variable and via the function of 
	globalDemo2. */

	/*staticGlobalString2 = "My static string update";
	cout << staticGlobalString2 << endl;
	printStaticGlobalString2();*/

	/**************************************************************/

	/* CASE 4
	This part tries to print the global variable globalString2
	declared here. After that, it calls the function of 
	globalDemo2 to print the globalString2 declared there. */

	/*cout << globalString2 << endl;
	printGlobalString2();*/

	/**************************************************************/

	system("pause");
	return 0;
}