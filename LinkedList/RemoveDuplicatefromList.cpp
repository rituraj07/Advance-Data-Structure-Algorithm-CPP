/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* a) {
    ListNode *A=a;
    ListNode *t;
    while(A->next!=NULL)
    {
        if(A->val==A->next->val)
        {
            //t=A->next->next;
            //free(A->next);
            A->next=A->next->next->next;
        }
        else
        A=A->next;
    }
    return a;
}
