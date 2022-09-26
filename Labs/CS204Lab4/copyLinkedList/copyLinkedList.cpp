#include <iostream>

using namespace std;

struct node
{

	int id;
	node* next;

	//default constructor
	node::node()
		:id(0), next(NULL)
	{}

	//constructor
	node::node(int i, node* n)
		: id(i), next(n)
	{}

};

//This function takes head of a list as parameter and prints the list, note that parameter is taken without reference so head pointer still points the first node of the list in the main
void printList(node* head)
{
	if (head == NULL)
	{
		cout << "List is empty!\n";
	}
	cout << "\n";
	while (head != NULL) {
		cout << head->id << " ";
		head = head->next;
	}
	cout << "\n";
}

//This function takes head of a list as parameter and creates a new list, which is a copy of the given list then returns head of newly created list, note that parameter is taken without reference so head pointer still points the first node of the list in the main
node* copyList(node* head)
{
	if (head == NULL) // if list is empty, there is nothing to copy
	{
		return NULL;
	}

	node* res = new node(head->id, NULL); //creating a new memory allocation for the head of new list, so head of our new list has the same content but in different memory
	node* temp = res; //temporary pointer to iterate in our new list

	while (head->next != NULL)
	{ //iteration loop for our original list
		temp->next = new node(head->next->id, NULL); //for every node in our original list, creating a new node with the same value in our copy list but in different memory
		head = head->next;
		temp = temp->next;
	}
	return res;//returns the head of our newly created list
}

//This function takes head of a list as parameter and add given id to the beginning of the list, note that parameter is taken reference so head pointer still will be updated in the main also
void addToBeginning(int id, node*& head)
{
	node* newNode = new node(id, head);
	head = newNode;
}

//This function multiplies the each element of the list by it self, note that parameter is taken without reference so head pointer still points the first node of the list in the main
void Square(node* head)
{
	while (head != NULL)
	{
		head->id = (head->id) * (head->id);
		head = head->next;
	}
}

int main()
{

	node* firstList = new node(10, NULL); //my linked list, first node has id 10 and its next points to NULL

	//complete to a linked  list such that the finished list has:
	//elements: 1->...->9->10->NULL
	for (int i = 9; i > 0; i--)
	{
		addToBeginning(i, firstList);
	}

	//printing our firstList
	cout << "My firstList:";
	printList(firstList);

	node* secondList = copyList(firstList); //copies our firstList, assigns head of newly created list to secondList pointer

	//printing our secondList
	cout << "My secondList:";
	printList(secondList);

	//changing the values in our firstList
	Square(firstList);
	//adding one more node to our firstList
	addToBeginning(0, firstList);

	//printing our firstList again
	cout << "My firstList:";
	printList(firstList);

	//Note that changes done on our firstList does not affect our secondList, because copyList function copies values into new memory
	cout << "My secondList:";
	printList(secondList);
	system("pause");
	return 0;
}