/* 
Insertion in singly linked list at beginning
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *create(int a);
struct node *head;
void print(struct node *h);

int main()
{
    int n,a;
    head =NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       scanf("%d",&a);
       head=create(a);
       
    }
    print(head);
    return 0;
}

struct node *create(int a)
{
    struct node *temp=NULL;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=head;
    head=temp;
    return head;
}

void print(struct node *h)
{
    while(h!=NULL)
    {
        printf("%d ",h->data);
        h=h->next;
    }
    printf("\n");
}
