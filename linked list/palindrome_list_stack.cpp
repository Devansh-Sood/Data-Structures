#include<bits/stdc++.h> 
using namespace std;  
  
class Node { 
public: 
        int data; 
        Node(int d){ 
            data = d; 
        } 
        Node *ptr; 
}; 
  
bool isPalin(Node* head){ 
    stack<int>s;
    Node *h=head;
    int c=0,a=0;
    while(h!=NULL)
    {
        s.push(h->data);
        h=h->ptr;
        c++;
    }
    while(!s.empty())
    {
        if(s.top() == head->data)
        {
            a++;
            head=head->ptr;
            s.pop();
        }
        else
        {
            return false;
        }
    }
    if(c==a)
    {
        return true;
    }
} 

int main(){ 
  
    Node one =  Node(1); 
    Node two = Node(2); 
    Node three = Node(3); 
    Node four = Node(2); 
    Node five = Node(1); 
  
    five.ptr = NULL; 
    one.ptr = &two; 
    two.ptr = &three; 
    three.ptr = &four; 
    four.ptr = &five; 
    Node* temp = &one; 
  
    int result = isPalin(&one); 
    
    if(result == 1) 
            cout<<"isPalindrome is true\n"; 
    else
        cout<<"isPalindrome is false\n"; 
  
return 0; 
} 