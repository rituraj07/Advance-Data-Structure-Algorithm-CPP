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
    TreeNode* fn(vector<int>& p, vector<int>& in,int &ind,int l,int r)
    {
        if(l>r) return NULL;
        int pvt=l;
        while(in[pvt]!=p[ind]) pvt++;
        ind++;
        TreeNode* root=new TreeNode(in[pvt]);
        root->left=fn(p,in,ind,l,pvt-1);
        root->right=fn(p,in,ind,pvt+1,r);
        return root;
            
    }
    TreeNode* buildTree(vector<int>& p, vector<int>& in) {
        //TreeNode* root=p[0];
        int ind=0;
        return fn(p,in,ind,0,p.size()-1);
    }
};