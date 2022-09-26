/*Author: Dilara Akdogan
 *Date: March 2014
 *Operator Overloading with Mathematical Vectors (with the help of dynamic arrays)
*/

#ifndef _MATHVECTOR_H
#define _MATHVECTOR_H

using namespace std;

class MathVector
{
private:
	int* vector;
	int size;

public:
	MathVector(); // empty constructor
	MathVector(int); // constructor with vector size
	MathVector(const MathVector &); // copy constructor
	~MathVector(); // destructor
	const MathVector& operator=(const MathVector &); // assignment operator (=)
	const MathVector& operator+=(MathVector &); // += operator
	MathVector operator+(const MathVector &); // + operator
	MathVector operator||(MathVector &); // || (concatenation) operator

	void setElement(int, int); // set element in specified index
	int getElement(int); // get element in specified index
	void setSize(int); // set size of the vector
	int getSize(); // get size of the vector
};

#endif