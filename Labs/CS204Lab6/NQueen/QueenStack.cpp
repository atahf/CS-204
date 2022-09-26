#include <iostream>
#include "QueenStack.h"
using namespace std;

//************************************************
// Constructor to generate an empty stack.       *
//************************************************
QueenStack::QueenStack()
{
	top = NULL; 
}

//************************************************
// Member function push pushes the argument onto *
// the stack.                                    *
//************************************************
void QueenStack::push(StackNode n)
{
	StackNode *newNode = new StackNode(n.queenNumber, n.pos);

	// If there are no nodes in the list
	// make newNode the first node
	if (isEmpty())
	{
		top = newNode;
		newNode->next = NULL;
	}
	else	// Otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************
void QueenStack::pop(StackNode &num)
{
	StackNode *temp;

	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else	// pop value off top of stack
	{
		num.pos = top->pos;
		num.queenNumber = top->queenNumber;
		temp = top->next;
		delete top;
		top = temp;
	}
}

//****************************************************
// Member funciton isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************
bool QueenStack::isEmpty(void)
{
	bool status;

	if (top == NULL)
		status = true;
	else
		status = false;

	return status;
}

