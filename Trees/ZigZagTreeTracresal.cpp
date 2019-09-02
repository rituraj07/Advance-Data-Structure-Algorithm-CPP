/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void fn(TreeNode *A,vector<vector<int> > &v,int &c)
{
    queue<TreeNode*> q;
    vector<TreeNode*> t;
    vector<int> vv;
    if(A==NULL) return;
    q.push(A);
    vv.push_back(A->val);
    v.push_back(vv);
    vv.clear();
    while(!q.empty()||t.size()>0)
    {
        //cout
        if(q.empty()&&t.size()>0)
        {
            for(auto i:t)
            q.push(i);
            t.clear();
            if(c%2!=0)
            {
                v.push_back(vv);
                vv.clear();
            }
            else
            {
                reverse(vv.begin(),vv.end());
                v.push_back(vv);
                vv.clear();
            }
            c++;
        }
        TreeNode *temp=q.front();
        q.pop();
        
        if(temp->left!=NULL)
        {
            t.push_back(temp->left);
            vv.push_back(temp->left->val);
        }
        if(temp->right!=NULL)
        {
            t.push_back(temp->right);
            vv.push_back(temp->right->val); 
        }
        
    }
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    int c=0;
   vector<vector<int>> v;
   fn(A,v,c);
   return v;
}
