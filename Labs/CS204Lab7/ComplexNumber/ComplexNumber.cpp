/*Author: Zeynep Dogmus
 *Date: April 2013
 *Complex Numbers and Operator Overloading
*/
#include<iostream>
#include<iomanip>

#include"ComplexNumber.h"

using namespace std;

//********************************
// Constructor                   *
//********************************
ComplexNumber::ComplexNumber()
{
	real=new double;
	imaginary=new double;
}

//Sets the real number part of this complex number
void ComplexNumber::setReal(double newReal)
{
	*real=newReal;	
}

//Sets the imaginary number part of this complex number
void ComplexNumber::setImaginary(double newImaginary)
{
	*imaginary=newImaginary;	
}

//Returns the real number part of this complex number
double ComplexNumber::getReal() const
{
	return *real;
}

//Returns the imaginary number part of this complex number
double ComplexNumber::getImaginary() const
{
	return *imaginary;
}

//********************************
// Deep Copy Constructor         *
//********************************
ComplexNumber::ComplexNumber(const ComplexNumber &copy)
{
	real=new double;
	imaginary=new double;
	*real=*(copy.real);
	*imaginary=*(copy.imaginary);
}

//********************************
// Assignment operator           *                                    
//********************************
const ComplexNumber & ComplexNumber::operator = (const ComplexNumber & rhs)
{
	if (this != &rhs)
	{
		*real=*(rhs.real);
		*imaginary=*(rhs.imaginary);
	}
	return *this;
}

//*********************************************
// Operator overloading                       *
// Subtract rhs from this complex number      *
//*********************************************
const ComplexNumber & ComplexNumber::operator-=(ComplexNumber &rhs)
{
	*real = *real - rhs.getReal();
	*imaginary = *imaginary - rhs.getImaginary();
	return *this;
}

//*******************************************************************
// Operator overloading for multiplication                          *  
// Multiply this complex number with rhs and return the new result  *
// (a+bi)*(c+di) = ac-bd + (ad+bc)i   (Keep in mind that i^2=-1)    *
//*******************************************************************
ComplexNumber ComplexNumber::operator*(const ComplexNumber &rhs)
{
	ComplexNumber result;
	double realResult,imaginaryResult;

	realResult = ((*real) * rhs.getReal()) - ((*imaginary) * rhs.getImaginary()); 
	imaginaryResult = ((*real) * rhs.getImaginary()) + ((*imaginary) * rhs.getReal());

	result.setReal(realResult);
	result.setImaginary(imaginaryResult);

	return result;
}

//********************************
// Destructor                    *                                    
//********************************
ComplexNumber::~ComplexNumber()
{
	delete real;
	delete imaginary;
}
