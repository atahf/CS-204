/*Author: Zeynep Dogmus
 *Date: March 2013
 *Operator Overloading with Queue
*/
#ifndef DYNAMICSTRINGQUEUE_H
#define DYNAMICSTRINGQUEUE_H

#include <string>
using namespace std;

struct QueueNode
{
	string value;
	QueueNode *next;
	QueueNode(string str, QueueNode *ptr = NULL)
	{
		value = str;
		next = ptr;
	}
};

class DynamicStringQueue
{
	private:
		QueueNode *front;
		QueueNode *rear;

	public:
		DynamicStringQueue();
		~DynamicStringQueue();
		DynamicStringQueue(const DynamicStringQueue &);

		void enqueue(string);
		void dequeue(string &);
		bool isEmpty() const; 
		void clear(void);

		QueueNode* GetFront();
		QueueNode* GetRear();
		void createClone(const DynamicStringQueue &);
		const DynamicStringQueue & operator = (const DynamicStringQueue & rhs);
		bool operator<(int);

};


#endif