/*

For example, in the following tree, sum of nodes at odd level is (5 + 1 + 4 + 8) which is 18.
And sum of nodes at even level is (2 + 6 + 3 + 7 + 9) which is 27.
The output for following tree should be 18 – 27 which is -9

*/



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
    int p=0,n=0,d=0,c=0;
    queue<Node *> q;
    Node * cur;
    q.push(root);
    q.push(NULL);
    c=1;
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
            c++;
        }
        else{
            if(cur->left)
            q.push(cur->left);
            if(cur->right)
            q.push(cur->right);
            
            cout<<cur->data<<" ";
            if(c%2!=0)
            {
                p=p+cur->data;
            }
            else
            {
                n=n+cur->data;
            }
        }
    }
    cout<<"\n"<<p-n;
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
    Node* root = newNode(5); 
    root->left = newNode(2); 
    root->right = newNode(6); 
    root->left->left = newNode(1); 
    root->left->right = newNode(4); 
    root->left->right->left = newNode(3); 
    root->right->right = newNode(8); 
    root->right->right->right = newNode(9); 
    root->right->right->left = newNode(7); 
  
    cout << "Level Order traversal of binary tree is \n"; 
    printLevelOrder(root); 
    return 0; 
} 
