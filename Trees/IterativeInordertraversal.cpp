/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        map<TreeNode*,int> m;
        stack<TreeNode*> s;
        vector<int> v;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* curr=s.top();
            if(curr==NULL) 
            {
                s.pop();
                continue;
            }
            
            if(m[curr]==0)
                s.push(curr->left);
            else if(m[curr]==1)
                v.push_back(curr->val);
            else if(m[curr]==2)
                s.push(curr->right);
            else
                s.pop();
            m[curr]++;
        }
        return v;
    }
};