#include <iostream> 
using namespace std; 
  
struct Node { 
    int key; 
    struct Node* next; 
}; 
  
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->next = NULL; 
    return temp; 
} 
  
// A utility function to print a linked list 
void printList(Node* head) 
{ 
    while (head != NULL) { 
        cout << head->key << " "; 
        head = head->next; 
    } 
    cout << endl; 
} 
  
// Function to detect and remove loop 
// in a linked list that may contain loop 
Node* detectAndRemoveLoop(Node* head) 
{ 
    Node *s=NULL;
    Node *f=NULL;
    Node *a=NULL;
    a=head;
    s=head;
    f=head;
    if(head==NULL || head->next==NULL)
    return NULL;
    while(head!=NULL)
    {
        s=s->next;
        f=f->next->next;
        if(s->key==f->key)
        {
            break;
        }
    }
	if (s != f) 
        return NULL; 
    if(a->key==s->key)
    {
        return a;
    }
    while(a->key!=s->key)
    {
        a=a->next;
        s=s->next;
        if(a->key==s->key)
        {
            break;
        }
    }
    return s;
} 
  
/* Driver program to test above function*/
int main() 
{ 
    Node* head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 
  
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next; 
  
    Node* res = detectAndRemoveLoop(head); 
    if (res == NULL) 
        cout << "Loop does not exist"; 
    else
        cout << "Loop starting node is " << res->key; 
  
    return 0; 
}
