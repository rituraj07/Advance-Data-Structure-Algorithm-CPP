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
    bool fn(TreeNode* root,int l,int u)
    {
        if(root==NULL)
            return true;
        int ans=true;
        if(l!=-1)
        {
            if(root->val<=l)
                return false;
        }
        if(u!=-1)
        {
            if(root->val>=u)
            {   
                return false;
            }
        }
        return ans&fn(root->left,l,root->val)&fn(root->right,root->val,u);
    }
    bool isValidBST(TreeNode* root) {
        return fn(root,-1,-1);
        
    }
};