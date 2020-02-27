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

treenode *construct(int *in,int *pre,int ins,int ine,int pres,int pree)
{
    if(ins>ine)    // I always forget base condition of recursion
    {
        return NULL;
    }
    int rootnode=pre[pres];
    int rootindex=-1,i=0;
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
    int prels=pres+1;
    int prele=inle-inls+prels;
    int prers=prele+1;
    int prere=pree;
    treenode *root=treenode_new(rootnode);
     root->left=construct(in,pre,inls,inle,prels,prele);
     root->right=construct(in,pre,inrs,inre,prers,prere);
    return root;
}

treenode* buildTree(int *pre,int psize,int *in,int insize) {
    return construct(in,pre,0,insize-1,0,psize-1);
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
    int in[] ={ 9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7 }; 
        int pre[] ={ 1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13 };
    int n = sizeof(in) / sizeof(in[0]); 
    treenode *root=NULL;
    root=buildTree(pre,n,in,n);
   
    preOrder(root); 
  
    return 0; 
} 