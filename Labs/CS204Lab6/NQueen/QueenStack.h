#include <iostream>

//Position struct
struct Position 
{
	int row, col; //Identifies position of a specific cell, Position(0,0) -> top left corner of the board
	Position(int x_ = 0, int y_ = 0) : row(x_), col(y_) {};
};

//StackNode struct
struct StackNode 
{
	int queenNumber; //Unique identifier for queens, which will be always equal to current column number(0 or 1 or .. or N) since algorithm puts queens column by column
	Position pos; //When we need to backtrack, we can directly return the position of lastly put queen
	StackNode *next;
	StackNode(int q = 0, Position p = Position(), StackNode* n = NULL) :queenNumber(q), pos(p), next(n) {};
};

class QueenStack
{
private:
	StackNode *top;

public:
	QueenStack(void);
	void push(StackNode);
	void pop(StackNode&);
	bool isEmpty(void);
};
