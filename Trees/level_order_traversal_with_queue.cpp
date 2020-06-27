#include <iostream>
#include<queue>
using namespace std;

struct Node 
{ 
    int data; 
    struct Node *left, *right; 
};

void printLevelOrder(Node *root)
{
    queue<Node *> q;
    Node * cur;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(q.empty())
        break;
        if(cur==NULL)
        {
            q.push(NULL);
            cout<<"\n";
        }
        else{
            if(cur->left)
            q.push(cur->left);
            if(cur->right)
            q.push(cur->right);
            
            cout<<cur->data<<" ";
        }
    }
}

Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create binary tree shown in above diagram 
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    cout << "Level Order traversal of binary tree is \n"; 
    printLevelOrder(root); 
    return 0; 
} 
