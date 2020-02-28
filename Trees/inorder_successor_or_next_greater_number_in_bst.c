#include <stdio.h> 
#include <stdlib.h> 

struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
    struct node* parent; 
}; 
  


struct node *find(struct node *root,int temp)
{
    struct node *c=NULL;
    if(root == NULL)
    return NULL;
    if(root->data == temp)
    {
        return root;
    }
    if(temp > root->data)
    {
        c=find(root->right,temp);
    }
    else if(temp < root->data)
    {
        c=find(root->left,temp);
    }
    return c;
}


struct node *inOrderSuccessor(struct node *root , int temp)
{
    //search the node -O(h)
    struct node *successor = NULL;
    struct node *current = find(root,temp);
    if(current == NULL)
    return NULL;
    
    //case 1: Node has right subtree
    if(current->right!=NULL)
    {
        struct node *t=current->right;
        while(t->left!=NULL)
        {
            t=t->left;
        }
        return t;
    }
    
    //case 2: No right right subtree
    else
    {
        struct node *ancestor = root;
        while(ancestor != current)
        {
            if(current->data<ancestor->data)
            {
                successor = ancestor;
                ancestor=ancestor->left;
            }
            else
            ancestor=ancestor->right;
        }
    }
    return successor;
}





struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data   = data; 
  node->left   = NULL; 
  node->right  = NULL; 
  node->parent = NULL; 
    
  return(node); 
} 
  

struct node* insert(struct node* node, int data) 
{ 
  if (node == NULL) 
    return(newNode(data)); 
  else
  { 
    struct node *temp;   
  
  
    if (data <= node->data) 
    {     
         temp = insert(node->left, data); 
         node->left  = temp; 
         temp->parent= node; 
    } 
    else
    { 
        temp = insert(node->right, data); 
        node->right = temp; 
        temp->parent = node; 
    }     
   
      return node; 
  } 
}  
   

int main() 
{ 
  struct node* root = NULL, *succ, *min; 
  

  root = insert(root, 20); 
  root = insert(root, 8); 
  root = insert(root, 22); 
  root = insert(root, 4); 
  root = insert(root, 12); 
  root = insert(root, 10);   
  root = insert(root, 14);     
  int temp = 8; 
  
  succ =  inOrderSuccessor(root, temp); 
  if(succ !=  NULL) 
    printf("\n Inorder Successor of %d is %d ", temp, succ->data);     
  else
    printf("\n Inorder Successor doesn't exit"); 
  
  getchar(); 
  return 0; 
} 