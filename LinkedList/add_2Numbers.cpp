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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ans=l1;
        int c=0,x=0;
        while(l1!=NULL)
        {
            if(l2==NULL)
            {
                x++;
                break;
            }
            int v=l1->val;
            //cout<<l2->val+l1->val+c;
            l1->val=(l2->val+l1->val+c)%10;
            c=(c+v+l2->val)/10;
            //cout<<c;
            //c--;
            if(l1->next==NULL)
                break;
            if(l2->next==NULL)
            {
                x++;
                break;
            }
            l1=l1->next;
            l2=l2->next;
        }
        //return ans;
        if(x)
        {
            l1=l1->next;
            while(l1!=NULL)
            {
                int v=l1->val;
                l1->val=(l1->val+c)%10;
                c=(v+c)/10;
                if(l1->next==NULL)
                break;
                l1=l1->next;
            }
        }
        else
        {
            l2=l2->next;
            while(l2!=NULL)
            {
                int v=l2->val;
                ListNode* t=new ListNode((l2->val+c)%10);
                l1->next=t;
                l1=l1->next;
                l2=l2->next;
                c=(v+c)/10;
            }
        }
        //cout<<c<<" ";
        if(c)
        {
            //cout<<"k";
            ListNode* t=new ListNode(c);
                l1->next=t;
        }
        return ans;
        
    }
};