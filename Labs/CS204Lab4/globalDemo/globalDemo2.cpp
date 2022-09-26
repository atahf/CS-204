/***************************************************
globalDemo1 and globalDemo2 together demonstrate the use 
of global, extern and static global variables. The usages 
of these variables are illustrated in four cases.

The cases are explained in globalDemo1.cpp.

Author: Zeynep Dogmus
Date: Feb. 2013
****************************************************/
#include <iostream>
#include <string>

using namespace std;

string globalString = "My shopping cart: ";					//Global variable for case 1

static string staticGlobalString = "My second static global string";//Static global variable for case 2

static string staticGlobalString2 = "My static string";		//Static global variable for case 3

string globalString2 = "Globalstring1";						//Global variable for case 4

//Displays the first global string
void printGlobalString()
{
	cout << globalString << endl;
}
//Displays the first static global string
void printStaticGlobalString()
{
	cout << staticGlobalString << endl;
}
//Displays the second static global string
void printStaticGlobalString2()
{
	cout << staticGlobalString2 << endl;
}
//Displays the second global string
void printGlobalString2()
{
	cout << globalString2 << endl;
}
//Updates the first global string
void updateGlobalString(string newString)
{
	globalString+=newString;
}