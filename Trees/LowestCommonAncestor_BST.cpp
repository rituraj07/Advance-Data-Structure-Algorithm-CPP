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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       //if()
        int pval=root->val;
        int pv=p->val;
        int qv=q->val;
        if(pval<pv&&pval<qv)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(pval>pv&&pval>qv)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else
        {
            return root;
        }
    }
};