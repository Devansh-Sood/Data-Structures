#include<stdio.h> 
#include<stdlib.h> 

struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
};

struct snode
{
    struct tnode *t;
    struct snode *next;
};

struct tnode *newtNode(int d)
{
    struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void push(struct snode **head,struct tnode *q)
{
    struct snode *temp=(struct snode *)malloc(sizeof(struct snode));
    temp->t=q;
    temp->next=(*head);
    (*head)=temp;
}

struct tnode *pop(struct snode **head)
{
    struct tnode *res=NULL;
    res=(*head)->t;
    (*head)=(*head)->next;
    return res;
}

int isempty(struct snode **head)
{
    if((*head) == NULL)
    return 1;
    else
    return 0;
}

void inOrder(struct tnode *root)
{
    struct tnode *cur=root;
    struct snode *s1=NULL;
    int d=0;
    while(!d)
    {
        if(cur!=NULL)
        {
            push(&s1,cur);
            cur=cur->left;
        }
        else
        {
            if(!isempty(&s1))
            {
                cur=pop(&s1);
                printf("%d ",cur->data);
                cur=cur->right;
            }
            else
            d=1;
        }
    }
}

/* Driver program to test above functions*/
int main() 
{ 
  
  /* Constructed binary tree is 
            1 
          /   \ 
        2      3 
      /  \ 
    4     5 
  */
  struct tnode *root = newtNode(1); 
  root->left        = newtNode(2); 
  root->right       = newtNode(3); 
  root->left->left  = newtNode(4); 
  root->left->right = newtNode(5);  
  
  inOrder(root); 
  
  return 0; 
}