/************************************
*Modified by Gizem Gezici
*Date: 05.03.2012
*Dynamic One-Dimensional and Two-Dimensional Array Creation
*Last Modified: 29.2.2016
************************************/

#include <iostream>
#include <string>

using namespace std;

void PrintMatrix(int **matrix, int size)
{
	for(int i=0; i<size; i++)
	{
		cout << "Row " << (i+1) << " :" << endl; 
		for(int j=0; j<size; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void DeleteMatrix(int ** matrix, int size)
{
	for(int i=0; i<size; i++)
	{
		delete [] matrix[i];
	}
	delete [] matrix;
}

int main()
{
	int arraysize = 0;
	cout << "Please enter a size (min. 5) for dynamic array creations!" << endl; // added (min. 5) - 29.2.16
	cin.clear();
	cin >> arraysize;

	//One dimensional dynamic array creation
	int* dArray = new int[arraysize];
	dArray[0] = 6;

	//Two dimensional dynamic array creation
	int** dmatrix = new int*[arraysize];
	for(int i =0; i<arraysize; i++)
	{
		dmatrix[i] = new int[arraysize];
	}

	//Process on dynamic matrix
	for(int i=0; i<arraysize; i++)
	{
		for(int j=0; j<arraysize; j++)
		{
			dmatrix[i][j] = ((i+1)*10) + (j+1);
		}
	}

	PrintMatrix(dmatrix, arraysize);
	cout << endl;

	//Exchange the two rows of the matrix (3th and 5th rows)
	int* temp = dmatrix[2];
	dmatrix[2] = dmatrix[4];
	dmatrix[4] = temp;

	//After exchange print the matrix again
	cout << "After exchanging the rows of the matrix, printing the matrix..." << endl;
	PrintMatrix(dmatrix, arraysize);
	DeleteMatrix(dmatrix, arraysize);

	//deallocate one-dimensional dynamic array as well - 29.2.16
	delete [] dArray;

	system("pause");
	return 0;
}