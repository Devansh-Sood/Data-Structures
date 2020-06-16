/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int Solution::lPalin(ListNode* A)
{
    ListNode *slow=A;
    ListNode *fast=A;
    ListNode *prev_slow=NULL;
    ListNode *mid=NULL;
    ListNode *second=NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        prev_slow=slow;
        slow=slow->next;
    }
    if(fast!=NULL)
    {
        mid=slow;
        slow=slow->next;
    }
    second=slow;
  //  second=reverse(second);
    
    
     ListNode *cur=second;
    ListNode *f=NULL;
    ListNode *prev=NULL;
    while(cur!=NULL)
    {
        f=cur->next;
        cur->next=prev;
        prev=cur;
        cur=f;
    }
    second=prev;
    
    
    while(second!=NULL && A!=NULL){
        if(A->val==second->val)
        {
             A=A->next;
        second=second->next;
        }
        else
        {
            return 0;
        }
       
    }
    return 1;
}
