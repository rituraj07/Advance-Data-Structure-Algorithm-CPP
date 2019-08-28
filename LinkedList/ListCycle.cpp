/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if(A==NULL||A->next==NULL)
        return NULL;
    ListNode *slow=A;
    ListNode *fast=A->next;
    set<ListNode*> s;
    while(A!=NULL)
    {
        s.insert(A);
        A=A->next;
        if(s.find(A)!=s.end())
        {
            return A;
        }
        
    }
    return NULL;
}
