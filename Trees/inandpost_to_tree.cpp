#include <iostream>
using namespace std;

struct treenode { 
    int data; 
    treenode *left, *right; 
}; 

treenode *treenode_new(int rootnode)
{
    treenode *root=(treenode *)malloc(sizeof(treenode));
    root->data=rootnode;
    root->left=root->right=NULL;
    return root;
}

treenode *construct(int *in,int* pos,int ins,int ine,int poss,int pose)
{
    if(ins>ine)
     {
         return NULL;
     }
     int rootnode=pos[pose];
     int rootindex;
     int i;
     for(i=ins;i<=ine;i++)
     {
         if(rootnode==in[i])
         {
             rootindex=i;
             break;
         }
     }
    int inls=ins;
    int inle=rootindex-1;
    int inrs=rootindex+1;
    int inre=ine;
    int posls=poss;
    int posle=inle-inls+posls;
    int posrs=posle+1;
    int posre=pose-1;
    treenode *root=treenode_new(rootnode);
    root->left=construct(in,pos,inls,inle,posls,posle);
    root->right=construct(in,pos,inrs,inre,posrs,posre);
    return root;

    
}
  
treenode* buildTree(int* pos, int posSize, int* in, int inSize) {
    return construct(in,pos,0,inSize-1,0,posSize-1);
}

void preOrder(treenode* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 

int main() 
{ 
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 }; 
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 }; 
    int n = sizeof(in) / sizeof(in[0]); 
    treenode *root=NULL;
    root=buildTree(post,n,in,n);
   
    preOrder(root); 
  
    return 0; 
} 