/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int c=0;
    ListNode *head=new ListNode(0);
    ListNode *ans=head;
    while(A!=NULL&&B!=NULL)
    {
        int v=A->val+B->val+c;
        if(v>9)
        {
            v=v%10;
            c=1;
        }
        else
        {
            c=0;
        }
        ListNode *nn=new ListNode(v);
        head->next=nn;
        head=nn;
        A=A->next;
        B=B->next;
    }
    while(A!=NULL)
    {
        int v=A->val+c;
        if(v>9)
        {
            v=v%10;
            c=1;
        }
        else
        {
            c=0;
        }
        ListNode *nn=new ListNode(v);
        head->next=nn;
        head=nn;
        A=A->next;
    }
    while(B!=NULL)
    {
        int v=B->val+c;
        if(v>9)
        {
            v=v%10;
            c=1;
        }
        else
        {
            c=0;
        }
        ListNode *nn=new ListNode(v);
        head->next=nn;
        head=nn;
        B=B->next;
    }
    return ans->next;
}
