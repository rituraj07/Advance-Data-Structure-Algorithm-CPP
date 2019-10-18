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
    map<pair<TreeNode*,int>,int> dp;
    int fn(TreeNode* root,int k)
    {
       
        if(root==NULL)
            return 0;
        if(dp.find({root,k})!=dp.end())
            return dp[{root,k}];
        if(k==1)
        {
            dp[{root,k}]= max(fn(root->left,0)+fn(root->right,0)+root->val,fn(root->left,1)+
                       fn(root->right,1));
            return dp[{root,k}];
        }
        else
        {
            dp[{root,k}]= fn(root->left,1)+fn(root->right,1);
            return dp[{root,k}];
        }
    }
    int rob(TreeNode* root) {
        return fn(root,1);
    }
};