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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        int lvl=0,l;
        int ans=INT_MIN;
        q.push(root);
        ans=root->val;
        lvl=1;
        l=1;
        while(!q.empty()||!s.empty())
        {
            TreeNode *t=q.front();
            q.pop();
            if(t->left)
            s.push(t->left);
            if(t->right)
            s.push(t->right);
            if(q.empty())
            {
                lvl++;
                int a=0;
                while(!s.empty())
                {
                    q.push(s.top());
                    a+=s.top()->val;
                    s.pop();
                }
                if(a>ans)
                {    ans=a;
                 l=lvl;}
            }
            
        }
        // ans is maximum level sum we can get.
        return l;
    }
};