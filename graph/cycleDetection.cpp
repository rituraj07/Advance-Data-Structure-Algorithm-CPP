class Solution {
public:
    int vis[5001],vis1[5001];
    bool fn(vector<int> *v,int x)
    {
        if(vis[x]==1)
            return true;
        vis1[x]=1;
        vis[x]=1;
        bool ans=false;
        for(int i=0;i<v[x].size();i++)
        {
            if(vis[v[x][i]]==1)
                ans= true;
            else if(vis1[v[x][i]]!=1)
                ans=ans|fn(v,v[x][i]);
        }
        vis[x]=0;
        return ans;
    }
    bool canFinish(int nn, vector<vector<int>>& a) {
        bool ans=false;
        vector<int> v[5000];
        for(int i=0;i<a.size();i++)
        {
            v[a[i][0]].push_back(a[i][1]);
        }
        for(int i=0;i<nn;i++)
        {
            memset(vis,0,sizeof(vis));
            if(vis1[i]==0)
            {
                ans=ans|fn(v,i);
            }
            cout<<ans<< " ";
        }
        ans=!ans;
        return ans;
    }
};