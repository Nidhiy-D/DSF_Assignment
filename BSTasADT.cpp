#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{   public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data  = data;
        left = NULL;
        right = NULL;
    }
};

Node* insert_node(Node * root, int data){
    if(root == NULL)
    {
        root = new Node(data);
    }
    else if(data>=(root->data))
    {
        root->right = insert_node(root->right,data);
    }
    else
    {
        root->left = insert_node(root->left,data);
    }
    return root;
}

void inorder(Node * root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* Search(Node* root,int data)
{

    if(root == NULL || root->data == data)
    {
        return root;
    }
    else if(data>=root->data)
    {
        return Search(root->right,data);
    }
    else return Search(root->left,data);
}

int height(Node* root)
{

    if(root == NULL)
    {
        return -1;
    }

    int max_height = 1 + max(height(root->left),height(root->right));
    return max_height;
}

void level_wise_display(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<Node*> level;
    level.push(root);

    while(!level.empty())
    {
        auto presentnode = level.front();
        level.pop();
        cout<<presentnode->data<<" ";

        if(presentnode->left != NULL)
        {
            level.push(presentnode->left);
        }
        if(presentnode->right !=NULL)
        {

            level.push(presentnode->right);
        }
    }
    cout<<endl;
}

int get_max(Node* root)
{
    if(root ->right == NULL)
    {
        return root->data;
    }
    else return get_max(root->right);
}

int get_min(Node* root)
{
    if(root->left == NULL)
    {
        return root->data;
    }
    else return get_min(root->left);
}


Node* Delete(Node* root, int data)
{
   if(root == NULL)
   {
       return root;
   }

   else if(root->data == data)
   {
       if(root->left == NULL && root->right == NULL)
       {
           delete root;
           return NULL;
       }
       if(root->right == NULL)
       {
           int max_val = get_max(root->left);
           root->left = Delete(root->left,max_val);
           root->data = max_val;
           return root;

       }
       else
       {
           int min_val = get_min(root->right);
           root->right = Delete(root->right,min_val);
           root->data = min_val;
           return root;
       }
   }
   else if(data>=root->data)
   {
       root->right = Delete(root->right,data);
       return root;
   }
   else
   {
       root->left = Delete(root->left,data);
       return root;
   }
}

void Mirror(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    Node * temp = root->left;

    root->left = root->right;
    root->right = temp;

    Mirror(root->left);
    Mirror(root->right);
}

int main()
{
     Node* root = NULL;
     int choice;
     int data;

     do
     {
         cout<<"1 to insert a node \n 2 for Inorder Traversal \n 3 for Level Order traversal \n 4 to search a node \n 5 to delete a node \n 6 to Mirror a tree \n 7 to display tree height \n 8 to exit \n";
         cin>>choice;

         switch(choice)
         {
         case 1:
             cout<<"Enter data: ";
             cin>>data;
             root = insert_node(root,data);
             break;
         case 2:
            inorder(root);
            cout<<endl;
            break;
         case 3:
             level_wise_display(root);
             break;
         case 4:
             cout<<"Enter data: ";
             cin>>data;
             if(Search(root,data) == NULL)
             {
                 cout<<"Element not found"<<endl;

             }
             else
             {
                 cout<<"Element found."<<endl;
             }
             break;

         case 5:
             cout<<"Enter data: ";
             cin>>data;
             root = Delete(root,data);
             break;
         case 6:
            Mirror(root);
            break;

         case 7:
            int h = height(root);
            cout<<"Tree height is "<<h<<endl;
            break;
         }

     }while(choice!=8);

}
