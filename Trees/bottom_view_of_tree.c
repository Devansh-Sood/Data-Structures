lude <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;


  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/




struct pair
{
    int distance;
    struct node *treenode;
};

struct ll
{
    struct pair *pairnode;
    struct ll *next;
};

struct queue
{
    struct ll *front;
    struct ll *rear;
};

void push(struct queue *q,struct pair *p)
{
    struct ll *newnode=(struct ll *)malloc(sizeof(struct ll));
    newnode->pairnode=p;
    newnode->next=NULL;
    if(q->front ==NULL && q->rear==NULL)
    {
        q->front=newnode;
        q->rear=newnode;
    }
    else
    {
        q->rear->next=newnode;
        q->rear=newnode;
    }
}

void pop(struct queue *q)
{
    if(q->front==NULL)
    {
        return ;
    }
    if(q->front == q->rear)
    {
        q->front=NULL;
        q->rear=NULL;
        return;
    }
    else
    q->front=q->front->next;
}

int empty(struct queue *q)
{
    if (q->front == NULL)
    return 1;
    else
    return 0;
}

struct pair *peek(struct queue *q)
{
    return q->front->pairnode;
}

struct map
{
    int key;
    int value;
};

struct lmap
{
    struct map *m;
    struct lmap *next;
};

void pushbegin(struct lmap **head,struct map *newmap)
{
    struct lmap* nm=(struct lmap *)malloc(sizeof(struct lmap));
    nm->m=newmap;
    nm->next=NULL;
    if((*head)==NULL)
    {
        (*head) = nm;
    }
    else
    {
        nm->next=(*head);
        (*head)=nm;
    }
}

void pushend(struct lmap **head,struct map *newmap)
{
    struct lmap* nm=(struct lmap*)malloc(sizeof(struct lmap));
    nm->m=newmap;
    nm->next=NULL;
    struct lmap* current=(*head);
    while(current->next)
    {
        current=current->next;
    }
    current->next=nm;
}

int count(struct lmap **head , int k, int v)
{
    struct lmap* current=(*head);
    while(current)
    {
        if(current->m->key==k){
            current->m->value=v;
        return 1;
        }
        current=current->next;
    }
    return 0;
}

void topView( struct node *root) {

struct pair *p=(struct pair *)malloc(sizeof(struct pair));
int d;
d=0;
p->distance =d;
p->treenode=root;
struct queue *q=(struct queue *)malloc(sizeof(struct queue));
q->front=NULL;
q->rear=NULL;
push(q,p);
struct lmap *head=NULL;
while(!empty(q))
{
     struct pair *cur=peek(q);
    pop(q);
    struct map *m1=(struct map *)malloc(sizeof(struct map));
    if(count(&head,cur->distance,cur->treenode->data)==0){
            m1->key=cur->distance;
            m1->value=cur->treenode->data;
            if(m1->key <= 0)
            {
                pushbegin(&head , m1);
            }
            else
            {
                pushend(&head , m1);
            }
    }
   

    if(cur->treenode->left)
    {
    struct pair *nc=(struct pair *)malloc(sizeof(struct pair));
    nc->treenode = cur->treenode->left;
    nc->distance=cur->distance -1;
    push(q,nc);
    }
    if(cur->treenode->right)
    {
    struct pair *nc2=(struct pair *)malloc(sizeof(struct pair));
    nc2->treenode = cur->treenode->right;
    nc2->distance=cur->distance +1;
    push(q,nc2);
    }

}
while( head  )
{
printf("%d ",head->m->value);
head=head->next;
}
}




int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
	topView(root);
    return 0;
}
