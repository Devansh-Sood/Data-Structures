/*      Reverse a Linked List in groups of given size 

Given a linked list, write a function to reverse every k nodes (where k is an input to the function).

Input: 1->2->3->4->5->6->7->8->NULL, K = 3
Output: 3->2->1->6->5->4->8->7->NULL

Input: 1->2->3->4->5->6->7->8->NULL, K = 5
Output: 5->4->3->2->1->8->7->6->NULL    
*/



/*  ----------Linked list with O(n) time---------    */


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
 
  struct node
    {
        int data;
        struct node *next;
    };
    
    struct node *create(int n);
 void display(struct node *head);
 struct node *change(struct node *head);
 
void main()
{
    struct node *head=NULL;
    int n,i;
    scanf("%d",&n);
    head=create(n);
    head=change(head);
    display(head);
}

struct node *create(int n)
{
    struct node *head=NULL;
    struct node *temp=NULL;
    struct node *tail=NULL;
  //  head=(struct node *)malloc(sizeof(struct node *));
//    p=(struct node *)malloc(sizeof(struct node ));
     tail=(struct node *)malloc(sizeof(struct node ));
    int i;
    for(i=0;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node ));
       
        printf("Enter Data for : %d\n",i+1);
        scanf("%d",&(temp->data));
        temp->next=NULL;
        
        if(head == NULL)
        {
            head = temp;
            tail=temp;
        }
        else
        {
            
            tail->next=temp;
            tail=temp;
        }
    }
    return head;
}
void display(struct node *head)
{
   // struct node *p=head;
    while(head != NULL)
    {
        printf("%d\n",head->data);
        head=head->next;
    }
}

struct node *change(struct node *head)
{
    struct node *curr=head;
    struct node *p=NULL;
    struct node *f=NULL;
    int c=0;
    if(head==NULL)
    {
        return NULL;
    }
    while( c<2 && curr!=NULL)
    {
        f=curr->next;
        curr->next=p;
        p=curr;
        curr=f;
        c++;
    }
    
    head->next=change(curr);
    return p;
}
