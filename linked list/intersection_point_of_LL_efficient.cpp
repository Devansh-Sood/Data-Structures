// C++ program to get intersection point of two linked list 
#include <bits/stdc++.h> 
using namespace std; 
  
/* Link list node */
class Node { 
public: 
    int data; 
    Node* next; 
}; 
  
int length(Node *h)
{
    int c=0;
    while(h!=NULL)
    {
        c++;
        h=h->next;
    }
    return c;
}
  
struct Node *intersection(Node *p,Node *q)
{
    int m=length(p);
    int n=length(q);
    int d=m-n;
    if(p==NULL)
    return q;
    if(q==NULL)
    return p;
    if(m<n)
    {
        Node *temp=NULL;
        temp=q;
        q=p;
        p=temp;
        d=n-m;
    }
    for(int i=0;i<d;i++)
    {
        p=p->next;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p==q)
        {
            return p;
        }
        p=p->next;
        q=q->next;
    }
    return NULL;
}
  
// Driver Code 
int main() 
{ 
    /*  
        Create two linked lists  
      
        1st 3->6->9->15->30  
        2nd 10->15->30  
      
        15 is the intersection point  
    */
  
    Node* newNode; 
  
    // Addition of new nodes 
    Node* head1 = new Node(); 
    head1->data = 10; 
  
    Node* head2 = new Node(); 
    head2->data = 3; 
  
    newNode = new Node(); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
  
    cout << "The node of intersection is " << intersection(head1, head2)->data; 
} 