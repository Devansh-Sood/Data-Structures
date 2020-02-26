#include <bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    Node * left; 
    Node* right; 
    int hd; 
    int data; 
}; 
  
Node* newNode(int key) 
{ 
    Node* node=new Node(); 
    node->left = node->right = NULL; 
    node->data=key; 
    return node; 
} 
  
void bottomview(Node* root) 
{ 
    queue<Node *>q;
    map<int,int>m;
    int hd=0;
    q.push(root);
    while(q.size())
    {
        root=q.front();
        q.pop();
        hd=root->hd;
        m[hd]=root->data;
        if(root->left)
        {
            q.push(root->left);
            root->left->hd=hd-1;
        }
        if(root->right)
        {
            q.push(root->right);
            root->right->hd=hd+1;
        }
    }
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second<<" ";
    }
} 
   
int main() 
{ 
    /* Create following Binary Tree  
            1  
        / \  
        2 3  
        \  
            4  
            \  
            5  
            \  
                6*/
   Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->left->right->right = newNode(5); 
    root->left->right->right->right = newNode(6); 
    cout<<"Following are nodes in bottom view of Binary Tree\n";  
    bottomview(root); 
    return 0; 
} 