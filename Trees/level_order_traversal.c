#include<stdio.h> 
#include<stdlib.h> 

struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *newtNode(int d)
{
    struct tnode *temp= (struct tnode *)malloc(sizeof(struct tnode));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int height(struct tnode *root)
{
    if(root==NULL)
    return 0;
    int l=height(root->left);
    int r=height(root->right);
    if(l>r)
    return (l+1);
    else
    return (r+1);
}

void printGivenLevel(struct tnode* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
}

void printLevelOrder(struct tnode* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
} 

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
  
   printLevelOrder(root);
  
  return 0; 
}