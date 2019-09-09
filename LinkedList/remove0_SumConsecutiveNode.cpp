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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> m;
        ListNode *root=new ListNode(0);
        root->next=head;
        m[0]=root;
        int ac=0;
        while(head!=NULL)
        {
            ac+=head->val;
            //cout<<ac<<" ";
            if(m.find(ac)!=m.end())
            {
                ListNode *st=m[ac];
                ListNode *t=st;
                int aux=ac;
                while(t!=head)
                {
                    t=t->next;
                    aux+=t->val;
                    if(t!=head)
                        m.erase(aux);
                }
                st->next=head->next;
            }
            else
            {
                m[ac]=head;
            }
            head=head->next;
        }
        return root->next;
    }
};