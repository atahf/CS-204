/*Author: Dilara Akdogan
 *Date: March 2014
 *Operator Overloading with Mathematical Vectors (with the help of dynamic arrays)
*/

#include "MathVector.h"
#include <iostream>

using namespace std;

// constructor
MathVector::MathVector()
{
	size = 0;
	vector = NULL;
}

// constructor with vector size
MathVector::MathVector(int psize)
{
	vector = new int[psize];
	size = psize;
}

// destructor
MathVector::~MathVector()
{
	size = 0;
	delete[] vector;
}

// copy constructor - deep copy
MathVector::MathVector(const MathVector & copy)
{
	size = copy.size;
	vector = new int[size]; // deep copy

	for(int i = 0; i < size; i++)
	{
		vector[i] = copy.vector[i];
	}
}

// assignment operator
const MathVector& MathVector::operator=(const MathVector & rhs)
{
	if (this != &rhs) // if they are not already equal
	{
		// first delete left hand side
		size = 0;
		delete[] vector;

		// create new vector for left hand side
		size = rhs.size;
		vector = new int[size];

		for(int i = 0; i < size; i++)
		{
			vector[i] = rhs.vector[i]; // assign content
		}
	}

	return *this;
}

// += operator
const MathVector& MathVector::operator+=(MathVector & rhs)
{
	for(int i = 0; i < size; i++) // assumption: lhs and rhs have the same size
	{
		vector[i] = vector[i] + rhs.vector[i];
	}

	return *this; // return result in "this"
}

// + operator
MathVector MathVector::operator+(const MathVector & rhs)
{
	MathVector result(rhs.size);

	for(int i = 0; i < size; i++) // assumption: lhs and rhs have the same size
	{
		result.vector[i] = vector[i] + rhs.vector[i];
	}

	return result; // return result in new object
}

// concatenation operator
MathVector MathVector::operator||(MathVector & rhs)
{
	MathVector result(size + rhs.size);

	for(int i = 0; i < size; i++)
	{
		result.vector[i] = vector[i]; // copy left hand side vector
	}

	for(int i = size; i < rhs.size + size; i++)
	{
		result.vector[i] = rhs.vector[i-size]; // concatenate right hand side vector
	}

	return result;
}

// set element in the specified index
void MathVector::setElement(int index, int element)
{
	vector[index] = element;
}

// set size of the vector
void MathVector::setSize(int psize)
{
	size = psize;
	vector = new int[size];
}

// get size of the vector
int MathVector::getSize()
{
	return size;
}

// get element in the specified index
int MathVector::getElement(int index)
{
	return vector[index];
}