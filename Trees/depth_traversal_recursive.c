#include <stdio.h>
#include<stdlib.h>

struct node 
{ 
     int data; 
     struct node* left; 
     struct node* right; 
}; 
  
struct node* newNode(int data) 
{ 
     struct node* node = (struct node*)malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
}

void printInorder(struct node *root)
{
    if(root == NULL)
    {
        return ;
    }
    printInorder(root->left);
    printf("%d",root->data);
    printInorder(root->right);
}

void printPreorder(struct node *root)
{
    if(root == NULL)
    {
        return ;
    }
    printf("%d",root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(struct node *root)
{
    if(root == NULL)
    {
        return ;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d",root->data);
}

int main() 
{ 
     struct node *root  = newNode(1); 
     root->left             = newNode(2); 
     root->right           = newNode(3); 
     root->left->left     = newNode(4); 
     root->left->right   = newNode(5);  
  
     printf("\nPreorder traversal of binary tree is \n"); 
     printPreorder(root); 
  
     printf("\nInorder traversal of binary tree is \n"); 
     printInorder(root);   
  
     printf("\nPostorder traversal of binary tree is \n"); 
     printPostorder(root); 
  
     getchar(); 
     return 0; 
}