#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Node
{
public:
	Node* left;
	Node* right;
	int left_flag; // if left, rigth (flag) = 1 it has ancestor or else it has child
 	int right_flag;
	int data;
	Node( int x )
	{
		data = x;
		left_flag = 1;
		right_flag = 1;
	}
};

class TBT
{
public:

	Node* root, * dummy;

	TBT()
	{
		root = NULL;
		dummy = new Node( -1 );
		dummy->right_flag = 0;
		dummy->left = dummy;
		dummy->right = dummy;
	}

	void insertnode();
	void insert( Node*, Node* );
	void preorder();
	void inorder();
};

void TBT:: insertnode()
{
	Node* newnode = nullptr;
	int data;
	cout << "Enter the node element: " << endl;
	cin >> data;

	if ( dummy->left_flag == 1 )
	{
		root = newnode;
		root->left = dummy;
		root->right = dummy;
		dummy->left = root;
		dummy->left_flag = 0;
	}
	else
	{
		insert( root->left, newnode );
	}
}

void TBT::insert( Node* root, Node* newNode )
{
	if ( newNode->data < root->data )
	{
		if ( root->left_flag == 1 )
		{
			newNode->left_flag = root->right_flag;
			newNode->left = root->left;
			newNode->right = root->right;
			newNode->right_flag = 1;
			root->left = newNode;
			root->left_flag = 0;
		}

		else
		{
			insert( root->left, newNode );
		}
	}

	else
	{
		if ( root->right_flag == 1 )
		{
			newNode->right_flag = root->right_flag;
			newNode->right = root->right;
			newNode->left = root;
			newNode->left_flag = 1;
			root->right = newNode;
			root->right_flag = 0;
		}

		else
		{
			insert( root->right, newNode );
		}
	}
}

void TBT::preorder()
{
	Node* curr = root;
	while ( !curr )
	{
		printf( "%d ", curr->data );
		if ( curr->left != NULL )
			curr = curr->left;
		else if ( curr->right_flag == 1 )
			curr = curr->right;

		else
		{
			while ( curr->right != NULL && curr->right_flag == 0 )
				curr = curr->right;

			if ( curr->right = NULL )
				break;
			else
				curr = curr->right;
		}
	}

}

void TBT::inorder() {
	Node* temp;
	temp = root;
	while ( temp != dummy ) {
		while ( temp->left_flag== 0 ) {
			temp = temp->left;

		}
		cout << " " << temp->data;
		while ( temp->right_flag == 1 ) {
			temp = temp->right;
			if ( temp == dummy )
				return;
			cout << " " << temp->data << " ";
		}
		temp = temp->right;
	}
}

int main() {
	TBT t;
	int i, x, ch;
	do {
		cout << "\n\n------------------------Threaded Binary Tree------------------------\n";
		cout << "------------------------MENU------------------------\n";
		cout << "Enter your choice :\n1.Insert Element\n2.Preorder Traversal\n3.Inorder traversal\n4.Exit\n";
		cout << "Enter your choice : ";
		cin >> ch;
		switch ( ch ) {
		case 1:
			cout << "Enter the number of nodes : ";
			cin >> x;
			for ( i = 0; i < x; i++ )
				t.insertnode();
			break;

		case 2:
			t.preorder();
			break;

		case 3:
			t.inorder();
			break;

		}
	} while ( ch != 4 );
	return 0;
}
