#include<stdio.h> 
#include<stdlib.h> 

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int d)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
}

struct node *insert(struct node *root,int data)
{
    if(root==NULL)
    {
    root=newNode(data);
    }
    else
    {
        if(data <= root->data)
        {
            root->left=insert(root->left,data);
        }
        else
        {
            root->right=insert(root->right,data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main() 
{ 
  struct node *root = NULL; 
  root=insert(root,50);
  root=insert(root,30);
  root=insert(root,20);
  root=insert(root,40);
  root=insert(root,70);
  root=insert(root,60);
  root=insert(root,80);
   inorder(root);
  return 0; 
}