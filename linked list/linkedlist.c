
#include <stdio.h>


struct node

{

  int data;

  struct node *next;

};


struct node *create(int n);

void display(struct node *head);


int main()

{

    struct node *head=NULL;

    int i,n;

    scanf("%d",&n);

    head=create(n);

    display(head);

    return 0;

}

struct node *create(int n)

{

    int i;

    struct node *head=NULL;

    struct node *temp=NULL;

    struct node *p=NULL;

    for(i=0;i<n;i++)

    {

        temp=(struct node *)malloc(sizeof(struct node));

        scanf("%d",&(temp->data));

        temp->next=NULL;

        if(head==NULL)

        {

            head=temp;

        }

        else

        {

            p=head;

            while(p->next!=NULL)

            {

                p=p->next;

            }

            p->next=temp;

        }

    }

    return head;

}


void display(struct node *head)

{

    while(head!=NULL)

    {

        printf("%d",head->data);

        head=head->next;

    }

}