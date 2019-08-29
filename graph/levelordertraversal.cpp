/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > v;
    vector<TreeNode*> t;
    queue<TreeNode*> q;
    if(A==NULL)
    return v;
    q.push(A);
    vector<int> tt;
    tt.push_back(A->val);
    v.push_back(tt);
    while(!q.empty()||t.size()>0)
    {
        if(q.empty())
        {
            vector<int> a;
            for(auto i:t)
            {
                a.push_back(i->val);
                q.push(i);
            }
            v.push_back(a);
            t.clear();
        }
        TreeNode* n=q.front();
        q.pop();
        if(n->left!=NULL)
        {
            //cout<<n->left->val<<" ";
            t.push_back(n->left);
        }
        if(n->right!=NULL)
        {
           // cout<<n->right->val<<" ";
            t.push_back(n->right);
        }
        
        
    }
}
