#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;

	Node(int value)
	{
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* insert(Node* root, int value);
void inOrder(Node* root);
Node* minValue(Node* root);
Node* deleteNode(Node* root, int value);


Node* insert(Node* root, int value)
{
	if (root == NULL)
	{
		return new Node(value);
	}
	else if (root->value > value)
	{
		root->left = insert(root->left, value);
	}
	else if (root->value <= value)
	{
		root->right = insert(root->right, value);
	}

	return root;
}

void inOrder(Node* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->value << " ";
		inOrder(root->right);
	}
}

Node * minValue(Node * root)
{
	Node* current = root;
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

Node * deleteNode(Node * root, int value)
{
		if (root == NULL)
		{
			return root;
		}

		if (value < root->value)
		{
			root->left = deleteNode(root->left, value);
		}

		else if (value > root->value)
		{
			root->right = deleteNode(root->right, value);
		}
		else
		{
			//No child
			if (root->right == NULL && root->left == NULL)
			{
				delete root;
				root = NULL;
			}
			//One child 
			else if (root->right == NULL)
			{
				Node* temp = root;
				root = root->left;
				delete temp;
			}
			else if (root->left == NULL)
			{
				Node* temp = root;
				root = root->right;
				delete temp;
			}
			//two child
			else
			{
				Node* temp = minValue(root->right);
				root->value = temp->value;
				root->right = deleteNode(root->right, temp->value);
			}
		}

		return root;
}
