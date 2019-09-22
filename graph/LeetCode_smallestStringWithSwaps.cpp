class Solution {
public:
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& p) {
        int n=p.size();
        int v[100001];
        vector<int> g[100001];
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++)
        {
            g[p[i][0]].push_back(p[i][1]);
            g[p[i][1]].push_back(p[i][0]);
        }
        for(int i=0;i<=n;i++)
        {
            if(v[i]==0)
            {
                vector<int> ans;
                queue<int> q;
                q.push(i);
                ans.push_back(i);
                while(!q.empty())
                {
                    int x=q.front();
                    v[x]=1;
                    q.pop();
                    for(auto i:g[x])
                    {
                        if(v[i]==0)
                        {
                            v[i]=1;
                            q.push(i);
                            ans.push_back(i);
                        }
                    }
                }
                vector<char> t;
                for(int i=0;i<ans.size();i++)
                {
                    //cout<<ans[i]<<" ";
                    t.push_back(s[ans[i]]);
                }
                sort(t.begin(),t.end());
                sort(ans.begin(),ans.end());
                for(int i=0;i<t.size();i++)
                {
                    s[ans[i]]=t[i];
                }
            }
            
        }
        return s;
    }
};