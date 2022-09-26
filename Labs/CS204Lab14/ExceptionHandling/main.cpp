#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

class MyException
{
private:
	char* message;
	int messageCode;

public:
	MyException(char* msg, int errorcode);
	char* what();
	int whatCode();

};

class IntDivision {

public:

	IntDivision(int op1, int op2):operand1(op1), operand2(op2)
	{
		try
		{
			if(operand2 == 0)
			{
				result = "undefined";
				throw MyException("Divison by zero in class", 10);
			}
			int temp = op1 / op2;
			result = to_string(temp);
		}
		catch(MyException e)
		{
			cout<<"MyException in class: " << e.what() << endl;
		}
	}

	string getResult()
	{
		return result;
	}

private:
	int operand1; 
	int operand2;
	string result;
};


MyException::MyException(char*msg, int errorcode)
{
	cout << "exception object created" << endl;
	message = msg;
	messageCode = errorcode;

}

char* MyException::what()
{
	return message;
}

int MyException::whatCode()
{
	return messageCode;
}


double Divide(double a, double b)
{
	if (b == 0)
		throw MyException("Divison by zero", 10);
	return a/b;
}


void main()
{
	double i, j;
	
	cout << "enter data: ";

	while(cin >> i >> j)
	{
		try
		{	
			cout << Divide(i, j) << endl;
			if(i < 0)
			{
				throw i;
			}
			else
			{
				cout << sqrt(i) << endl;
			}
		}
		catch(MyException e)
		{
			cout << "MyException exception : " << e.what() << ". Code: " << e.whatCode() << endl;
		}
		catch (double num)
		{
			cout << "You're trying to get the square root of " << num << endl;
		}
		catch (char* msg)
		{
			cout << "char* exception : " << msg << endl;
		}
		catch(int k)
		{
			cout << "int exception : " << k << endl;
		}
		catch(...)
		{
			cout << "Generic exception "<< endl;
		}

		cout << "enter data: ";
	}


	IntDivision d1(2, 0);
	cout << "d1 result is " << d1.getResult() << endl;;


	IntDivision d2(4, 2);
	cout << "d2 result is " << d2.getResult() << endl;;

	system("Pause");
	return;
}