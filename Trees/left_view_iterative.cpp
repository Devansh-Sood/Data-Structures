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
  
void leftView(node* root) 
{ 
    queue<node *>q;
    q.push(root);
    int n,i;
    while(q.size())
    {
        n=q.size();
        for(i=1;i<=n;i++)
        {
            root=q.front();
        q.pop();
            if(i==1)
            cout<<root->data<<" ";
            if(root->left)
            q.push(root->left);
            if(root->right)
            q.push(root->right);
        }
    }
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