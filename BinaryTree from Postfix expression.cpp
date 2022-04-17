#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<iostream>
using namespace std;

class Node
{
public:
	char data;
	Node* left, * right;
};

class Tree
{
public:
	Node* root;
	Tree()
	{
		root = NULL;
	}
	void rec_inorder( Node* );
	void rec_preorder( Node* );
	void rec_postorder( Node* );
	void it_inorder( Node* );
	void it_preorder( Node* );
	void it_postorder( Node* );
	Node* expression();
};

Node* Tree::expression()
{
	cout << "Enter expression in lower case only." << endl;
	string dynamic_exp;
	cout << "Enter [ POSTFIX ] expression:";
	cin >> dynamic_exp;

	int s_len = dynamic_exp.length();

	char* exp = new char[ s_len + 1 ];

	strcpy_s( exp, s_len + 1, dynamic_exp.c_str() );

	cout << "\nYour Entered String : " << exp << endl;

	Node* temp;
	int i, top = -1;

	//int s_len = strlen(exp);

	Node** stack = (Node**)malloc( sizeof( Node* ) * s_len );
	int* flag = new int[ s_len ];
	for ( i = 0; exp[ i ] != '\0'; i++ )
	{
		if ( exp[ i ] >= 'a' && exp[ i ] <= 'z' )
		{
			temp = new Node;
			temp->data = exp[ i ];
			temp->left = temp->right = NULL;
			stack[ ++top ] = temp;
		}
		else
		{
			root = new Node;
			root->data = exp[ i ];
			root->left = root->right = NULL; // root creation for operator
			root->right = stack[ top-- ];
			root->left = stack[ top-- ];
			stack[ ++top ] = root;
		}
	}
	root = stack[ top-- ];
	return root;
}

void Tree::rec_inorder( Node* root )
{
	if ( root != NULL )
	{
		rec_inorder( root->left );
		cout << root->data;
		rec_inorder( root->right );
	}
}

void Tree::rec_preorder( Node* root )
{
	if ( root != NULL )
	{
		cout << root->data;
		rec_preorder( root->left );
		rec_preorder( root->right );
	}
}

void Tree::rec_postorder( Node* root )
{
	if ( root != NULL )
	{
		rec_postorder( root->left );
		rec_postorder( root->right );
		cout << root->data;
	}
}

void Tree::it_inorder( Node* root )
{
	struct Node* stack[20];
	int top = -1;
	while ( root != NULL || top != -1 )
	{
		if ( root != NULL )
		{
			stack[ ++top ] = root;
			root = root->left;
		}
		else
		{
			root = stack[ top-- ];
			cout << root->data;
			root = root->right;
		}
	}
}

void Tree::it_preorder( Node* root )
{
	struct Node* stack[ 20 ];
	int top = -1;
	stack[ ++top ] = root;
	while ( top != -1 )
	{
		root = stack[ top-- ];
		if ( root != NULL )
		{
			cout << root->data;
			stack[ ++top ] = root->right;
			stack[ ++top ] = root->left;
		}
	}
}

void Tree::it_postorder( Node* root )
{
	struct Node* stack[ 20 ];
	int top = -1;
	int flag[ 10 ];
	while ( top != -1 || root != NULL )
	{
		if ( root != NULL )
		{
			stack[ ++top ] = root;
			flag[ top ] = 0;
			root = root->left;
		}
		else
		{
			root = stack[ top ];
			if ( flag[ top ] == 1 )
			{
				cout << root->data;
				top--;
				root = NULL;
			}
			else
			{
				flag[ top ] = 1;
				root = root->right;
			}
		}
	}
}

int main()
{
	Tree s;
	//cout << "Press 1 to continue in menu" << endl;
	s.root = s.expression();
	int ch, ans;
	cout << "\n**MENU**";
	cout << "\n1.Recursive function for inorder";
	cout << "\n2.Recursive function for preorder";
	cout << "\n3.Recursive function for postorder";
	cout << "\n4.Nonrecursive function for inorder";
	cout << "\n5.Nonrecursive function for preorder";
	cout << "\n6.Nonrecursive function for postorder";
	do
	{
		cout << "\nENTER YOUR CHOICE:";
		cin >> ch;
		switch ( ch )
		{
		case 1:
			cout << "\n Inorder Exp with Recursive =>";
			s.rec_inorder( s.root );
			break;
		case 2:
			cout << "\n preorder Exp with Recursive =>";
			s.rec_preorder( s.root );
			break;
		case 3:
			cout << "\n postorder Exp with Recursive =>";
			s.rec_postorder( s.root );
			break;
		case 4:
			cout << "\n Inorder Exp with Non_Recursive =>";
			s.it_inorder( s.root );
			break;
		case 5:
			cout << "\n preorder Exp with Non_Recursive =>";
			s.it_preorder( s.root );
			break;
		case 6:
			cout << "\n postorder Exp with Non_Recursive =>";
			s.it_postorder( s.root );
			break;
		default:
			cout << "\n\t[ Option Out of Range ] valid range : [1 - 6]\n";
			break;
		}
		cout << "\n Do you want to continue: (Press 1 to continue, to Exit press 2) \n";
		cin >> ans;

	} while ( ans == 1 );

	_CrtDumpMemoryLeaks();
	//delete[] s.expression();

	return 0;
}
