/*
Author: Ýsmail Fatih Yýldýrým
Modified by Gizem Gezici
Modified Date: 02.05.2012
Bit operations
*/

#include<iostream>
using namespace std;

//These two functions will not be used in this lab
/*void MultiplyByTwo(unsigned int & num)
{
	unsigned int  mask = 1 << 31;
	if ( (num & mask) > 0) //In order to avoid overflow
		return;
	num = num << 1; //If there is no danger of overflow, then multiply it by 2 
					//(shift to the left) by one bit.
}

void DivideByTwo(unsigned int & num)
{
	num = num >> 1; //No danger of overflow! Just divide it by two by shifting one bit right.
}*/

//Gets the LSB and by shifting right and sets MSB to LSB
void CycleRight(unsigned int & num)
{
	unsigned int rightBit = num & 1 ;
	num = num >> 1;
	num = num | (rightBit << 31);
}

//Gets the MSB and by shifting left and sets LSB to MSB
void CycleLeft(unsigned int & num)
{
	 unsigned int leftBit = (1 << 31) & num ;
	 num  = num << 1;
	 num = num | (leftBit >> 31);
}

//the Hamming distance between two strings of equal length
//is the number of positions at which the corresponding symbols are different.
//In order to calculate the distance, it counts the 1's after the XOR operation.
//Since XOR of two different bits produce 1.
unsigned int HammingDistance(unsigned int a, unsigned int b)
{
	unsigned int c = a ^ b;
	unsigned int sum = 0;
	for(int i = 0; i < 32; i++)
	{
		sum += c & 1;
		c = c >> 1;
	}
	return sum;
}

//Prints the num in binary to the screen.
void PrintToScreen(unsigned int  num)
{
	char * list  = new char[8 * sizeof(unsigned int) + 1];
	list[32] = '\0';
	for(int i = 0; i < 32; i++)
	{
		if((num & 1) == 1)
		{
			list[31-i] = '1';
		}
		else
		{
			list[31-i] = '0';
		}

		num = num >> 1;
	}

	cout << list << endl;
}

int main()
{
	unsigned int a = 26354234;
	unsigned int b = 68768764;
	PrintToScreen(a);

	CycleRight(a);CycleRight(a);
	PrintToScreen(a);
	cout << endl;
	CycleRight(a);CycleRight(a);
	PrintToScreen(a);
	cout << endl;

	PrintToScreen(b);
	CycleLeft(b);CycleLeft(b);
	PrintToScreen(b);
	cout << endl;
	
	CycleLeft(a);
	PrintToScreen(a);
	cout << endl;

	unsigned int c = HammingDistance(a,b);
	cout << c << endl;
	cout << endl;


	cin.get();
	cin.ignore();
	return 0;
}