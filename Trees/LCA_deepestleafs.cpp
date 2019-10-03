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
    TreeNode* lca(TreeNode* root,int n1,int n2)
    {
        if(root==NULL) return root;
        if(root->val==n1||root->val==n2) return root;
        TreeNode* l=lca(root->left,n1,n2);
        TreeNode* r=lca(root->right,n1,n2);
        if(l!=NULL&&r!=NULL) return root;
        if(l==NULL) return r;
        return l;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        vector<TreeNode*> s,sp;
        q.push(root);
        while(!q.empty())
        {
            while(!q.empty())
            {
            TreeNode* n=q.front();
            q.pop();
            if(n->left)
            {
                s.push_back(n->left);
            }
            if(n->right)
            {
                s.push_back(n->right);
            }
            }
            if(s.size()==0)
                break;
            for(int i=0;i<s.size();i++)
                q.push(s[i]);
            sp.clear();
            sp=s;
            s.clear();
        }
        TreeNode* v=sp[0];
        for(int i=0;i<sp.size();i++)
        {
            v=lca(root,s[i]->val,v->val);
            //cout<<v->val<<" ";
        }
        return v;
    }
};