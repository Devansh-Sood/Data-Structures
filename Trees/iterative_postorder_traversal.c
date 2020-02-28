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

void postOrder(struct tnode *root)
{
   struct tnode *cur=root;
   struct snode *s1=NULL;
   struct snode *s2=NULL;
   push(&s1,cur);
  while(!empty(&s1))
  {
      cur=pop(&s1);
      push(&s2,cur);
      if(cur->left)
      push(&s1,cur->left);
      if(cur->right)
      push(&s1,cur->right);
  }
  while(!empty(&s2))
  {
      cur=pop(&s2);
      printf("%d ",cur->data);
  }
}

int main() 
{ 

/* Constructed binary tree is 
            1 
          /   \ 
        2      3 
      /  \    /  \
    4     5  6    7
  */

  struct tnode *root = NULL; 
  root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    
  
  postOrder(root); 
  
  return 0; 
}