/*Author: Dilara Akdogan
 *Date: March 2014
 *Operator Overloading with Mathematical Vectors (with the help of dynamic arrays)
*/

#include "MathVector.h"
#include <iostream>

using namespace std;

// print vector in the format: <1, 2, 3, 4, 5, 6, 7>
void printVector(MathVector vector)
{
	cout << "<";

	for(int i = 0; i < vector.getSize()-1; i++)
	{
		cout << vector.getElement(i) << ", ";
	}

	cout << vector.getElement(vector.getSize()-1) << ">" << endl << endl;
}

int main()
{
	MathVector v1; // empty constructor
	v1.setSize(7); // set size

	MathVector v2(5); // constructor with vector size
	MathVector v3(5); // constructor with vector size

	MathVector sumResult(5), conResult1(12), conResult2; // different constructors
	MathVector emptyVector;

	//set elements of v1
	for(int i = 0; i < 7; i++)
	{
		v1.setElement(i, i*7);
	}
	cout << "v1 = ";
	printVector(v1);

	// set elements of v2
	for(int i = 0; i < 5; i++)
	{
		v2.setElement(i, i+1);
	}
	cout << "v2 = ";
	printVector(v2);

	// set elements of v3
	for(int i = 0; i < 5; i++)
	{
		v3.setElement(i, i*2);
	}
	cout << "v3 = ";
	printVector(v3);

	MathVector v4(v2); // copy constructor
	cout << "v4 = ";
	printVector(v4);

	// = and + operators
	sumResult = v2 + v3;
	cout << "v2 + v3 = ";
	printVector(sumResult);
	
	// += operator
	v4 += v2;
	cout << "v4 += v2 = " ;
	printVector(v4);	

	// || operator (concatenation)
	conResult1 = v1 || v4;
	cout << "v1 || v4 = ";
	printVector(conResult1);

	// || operator (concatenation)
	// conResult2 was empty initially
	conResult2 = v3 || v1;
	cout << "v3 || v1 = ";
	printVector(conResult2);

	// = operator (assignment) to an empty vector
	emptyVector = conResult2;
	cout << "Assignment of (v3 || v1) to an empty vector : ";
	printVector(emptyVector);

	// = operator (assignment) of different sized vectors
	v2 = conResult1; // v2: 5 elements, conResult1: 12 elements
	cout << "Assignment of (v1 || v4) to v2 : ";
	cout << "v2 = ";
	printVector(v2);

	system("pause");
	return 0;
}