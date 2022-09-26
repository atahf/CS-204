#include <iostream>
#include "QueenStack.h"

/*
This program solves famaous N-queen problem via stacks. N-queen problem
is to lay out N queens on a N*N chess board so that none of them attack
each other. This is a very classical Computer Science problem and
normally solved via recursion. The solution here uses stacks and an
approach called "backtracking". We aim to place one queen at each column
and we actually exhaustively search all combinations. When we get stuck
with one of the queens (columns), we backtrack and change the position
of the previous queen. When you run the code in DEBUG mode, backtracking
related verbose output is displayed.
*/

using namespace std;
#define N 4

void printSolution(int** board)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout <<  board[i][j] << " ";
        cout << "\n";
    }
}

//Function that returns true if given position is safe to put a new queen, otherwise false
bool isSafe(int** board, int row, int col)
{
    int i, j;

    if (row >= N)
    {
        return false;
    }

    //Checks if there is anouther queen on that row
    for (i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }

    }

    //Checks if there is another queen on upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    //Checks if there is another queen on lower diagonal
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j] == 1)
            {
                return false;
            }
    }

    return true;
}



void solveNQueen(int** board, QueenStack& myStack, int col)
{
    int row = 0;   // variable for iteration on rows
    StackNode tmp; //temporary StackNode for pop
    while (col < N)// if column is equal to N, we know that we have put N queen safely
    {
        #ifdef _DEBUG
            cout << "Trying queen number: " << col << " position: " << row << "," << col << "\n";
        #endif
        if (isSafe(board, row, col)) //if given position is safe to put queen
        {
            board[row][col] = 1; //change the value to 1 from 0
            myStack.push(StackNode(col, Position(row, col))); // push current position to the stack
            col++; //increase col, in other words next queen
            row = 0; // reset row iterator
        }
        else if(row < N - 1) //if we cannot put the queen at (row, col), try next row
        {
            row++;
        }
        else
        {
            #ifdef _DEBUG
                cout << "Could not place queen " << col << ", backtracking to queen "<< col - 1<<"\n";
            #endif
            myStack.pop(tmp); // if there isn't any row to try, find new suitable position for previous queen
            col = tmp.queenNumber;
            row = tmp.pos.row;
            board[row][col] = 0;
            row++; // we have already put that queen before, so need to update its row counter to check other suitable positions
        }

        #ifdef _DEBUG
            printSolution(board);
            cout << "-----------\n";
        #endif
    }
}

int main()
{
    //creating our stack, which will be used for backtracking
    QueenStack myStack;
    //creating our dynamic matrix, which will be used for simulation of the board
    int** board;
    //memory allocations
    board = new int*[N]; 
    for (int i = 0; i < N; i++) 
    {
        board[i] = new int[N];
    }

    //0 indicates empty cell while 1 indicates cell with queen
    //Therefore, initially fill the board with 0s
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    solveNQueen(board, myStack, 0);

    cout << "\n" << "Solution:\n";
    printSolution(board);

    StackNode tmp;
    while (!myStack.isEmpty()) //end of the program, prevent memory leaks
    {
        myStack.pop(tmp);
    }

    for (int i = 0; i < N; i++)
    {
        delete[] board[i];
    }
    delete[] board;
    return 0;
}