#include<stdio.h> 
#include<stdlib.h> 

struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
};

int height(struct tnode *root)
{
    int m,n;
    if(root == NULL)
    return -1;
    m=height(root->left);
    n=height(root->right);
    if(m>n)
    return m+1;
    else
    return n+1;
}

struct tnode *newNode(int d)
{
    struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int main() 
{ 

/* Constructed binary tree is 
            1 
          /   \ 
        2      3 
      /  \    /  \
    4     5  6    7
        /  \
       8    9
  */

  struct tnode *root = NULL; 
  root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->right->left=newNode(8);
    
    root->left->right->right=newNode(9);
    
  int s=height(root);
  printf("%d",s);
   
  
  return 0; 
}