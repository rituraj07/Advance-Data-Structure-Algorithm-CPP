/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t=head;
        ListNode* x=head;
        while(n--)
        {
            t=t->next;
            
        }
        if(t==NULL)
            return head->next; 
        while(t->next!=NULL)
        {
            t=t->next;
            x=x->next;
        }
        x->next=x->next->next;
        return head;
    }
    
};