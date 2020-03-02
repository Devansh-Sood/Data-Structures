#include <bits/stdc++.h> 
using namespace std; 
  
class node { 
public: 
    int data; 
    node *left, *right; 
}; 
  

node* newNode(int item) 
{ 
    node* temp = new node(); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
  int m=0;
  
  void leftrecur(node *root , int level)
  {
    if(root==NULL)
    return;
    if(m<level)
    {
        cout<<root->data<<" ";
        m=level;
    }
    leftrecur(root->left,level+1);
    leftrecur(root->right,level+1);
  }
  
void leftView(node* root) 
{ 
    leftrecur(root,1);
} 
  
int main() 
{ 
    node* root = newNode(12); 
    root->left = newNode(10); 
    root->right = newNode(30); 
    root->right->left = newNode(25); 
    root->right->right = newNode(40); 
  
    leftView(root); 
  
    return 0; 
}