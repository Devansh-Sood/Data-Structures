/*  Recursively Reversing a linked list

eg:- Input : Head of following linked list  
       1->2->3->4->NULL
Output : Linked list should be changed to,
       4->3->2->1->NULL

  */



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
 struct node *change(struct node*head);
 struct node *h1;
 
void main()
{
    struct node *head=NULL;
    int n,i;
    scanf("%d",&n);
    head=create(n);
    head=change(head);
    display(h1);
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

struct node *change(struct node *p)
{
    if(p->next==NULL)
    {
    h1=p;
    return p;
    }
    struct node *q=change(p->next);
    q->next=p;
    p->next=NULL;
    return p;
}
