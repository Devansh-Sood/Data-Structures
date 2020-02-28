#include<stdio.h> 
#include<stdlib.h> 

struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
};

struct snode
{
    struct tnode *t;
    struct snode *next;
};

struct tnode *newNode(int d)
{
    struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
    temp->data=d;
    temp->right=NULL;
    temp->left=NULL;
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
    struct tnode *r=NULL;
    r=(*head)->t;
    (*head)=(*head)->next;
    return r;
}

int empty(struct snode **head)
{
    if((*head)==NULL)
    return 1;
    else
    return 0;
}

void preOrder(struct tnode *root)
{
    struct tnode *cur=root;
    struct snode *s=NULL;
    int d=0;
    push(&s,cur);
    while(!empty(&s))
    {
        cur=pop(&s);
        printf("%d ",cur->data);
        if(cur->right)
        push(&s,cur->right);
        if(cur->left)
        push(&s,cur->left);
    }
}

int main() 
{ 
  
  /* Constructed binary tree is 
            10 
          /    \ 
         8      2 
       /  \    /
      3    5  2
  */
  struct tnode *root = newNode(10); 
  root->left        = newNode(8); 
  root->right       = newNode(2); 
  root->left->left  = newNode(3); 
  root->left->right = newNode(5); 
  root->right->left = newNode(2);   
  
  preOrder(root); 
  
  return 0; 
}