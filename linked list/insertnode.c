/*    ---------- Linked list with O(n) time insert node at ith position ---------    */
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
 struct node *input(int n);
 
void main()
{
    struct node *head=NULL;
    struct node *h1=NULL;
    int n,i;
    scanf("%d",&n);
    head=input(n);
//    head=create(n);
    display(head);
    h1=change(head);
    printf("After insertion the linked list is :");
    display(h1);
}

struct node *create(int a)
{
    struct node *head=NULL;
    struct node *temp=NULL;
    struct node *tail=NULL;
        temp=(struct node *)malloc(sizeof(struct node ));
        temp->data=a;
        temp->next=NULL;
        
       
    return temp;
}
void display(struct node *head)
{
   // struct node *p=head;
    while(head != NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
}

struct node *change(struct node *head)
{
    int a,b,i;
    printf("\nEnter the ith location and its value :");
    scanf("%d",&a);
    scanf("%d",&b);
    struct node *p=create(b);
    struct node *temp=NULL;
    temp=head;
    for(i=0;i<a;i++)
    {
        if(i==a-1)
        {
            p->next=temp->next;
            temp->next=p;
        }
        temp=temp->next;
    }
    return head;
}

struct node *input(int n)
{
    int i,a;
    struct node *head=NULL;
    struct node *temp=NULL;
    struct node *tail=NULL;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        temp=create(a);
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