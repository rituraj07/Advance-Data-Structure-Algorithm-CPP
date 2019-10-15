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
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* f=head->next;
        ListNode* s=head;
        while(f!=NULL&&f->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }
        f=s->next;
        s->next=NULL;
        
        return merge(sortList(head),sortList(f));
    }
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode dump(0);
        ListNode* curr=&dump;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                curr->next=l1;
                l1=l1->next;
            }
            else
            {
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1!=NULL)
        {
          curr->next=l1;  
        }
        else
        {
            curr->next=l2;
        }
        return dump.next;
    }
};