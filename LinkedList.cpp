#include <iostream>
using namespace std;


struct Node {
	int value;
	Node* next;
};

class List {

public:
	List() {
		this->head = NULL;
		this->tail = NULL;
	}

	void add(int value)
	{
		Node* temp = new Node;
		temp->value = value;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	void insertAtPosition(int value,int pos)
	{
		Node* temp = new Node;
		temp->value = value;

		Node* previous;
		Node* current;
		current = head;

		for (int i = 1; i < pos; i++)
		{
			previous = current;
			current = current->next;
		}

		previous->next = temp;
		temp->next = current;
	}

private:
	Node* head;
	Node* tail;
};
