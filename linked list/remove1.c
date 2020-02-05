/*  ----------Remove duplicate in sorted list---------   

For example if the linked list is 11->11->11->21->43->43->60 then removeDuplicates() should convert the list to 11->21->43->60.
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
    struct node *p=NULL;
    struct node *p1=NULL;
    int i=0;
    p=head;
   // p1=p->next;
    while(p->next!=NULL)
    {
            if(p->data == p->next->data)
            {
                p->next=p->next->next;
            }
            else
            p=p->next;
    }
    return head;
}
