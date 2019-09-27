#include<bits/stdc++.h>
using namespace std;
vector<int> v[10001],vt[100001];
set<set<int>> comp;
int vis[100001];
stack<int> st;
void dfs(int s)
{
    vis[s]=1;
    for(int i=0;i<v[s].size();i++)
    {
        if(vis[v[s][i]]==0)
        dfs(v[s][i]);
    }
    st.push(s);
}
void dfs2(int s,set<int> &c)
{
    vis[s]=1;
    c.insert(s);
    for(int i=0;i<vt[s].size();i++)
    {
        if(vis[vt[s][i]]==0)
        {
            dfs2(vt[s][i],c);
        }
    }
}
int main()
{
    while(1)
    {
        int n,a,b,e;
	    cin>>n;
        if(n==0)
            break;
        cin>>e;
        while(e--)
        {
            cin>>a>>b;
            v[a].push_back(b);
            vt[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
            }
        }
        memset(vis,0,sizeof(vis));
        while(!st.empty())
        {
            int i=st.top();
            st.pop();
            if(vis[i]==0)
            {
                set<int> c;
                dfs2(i,c);
                comp.insert(c);
            }
        }
        for(auto it:comp)
        {
            int no=0;
            for(auto i:it)
            {
                for(int k=0;k<v[i].size();k++)
                {
                    if(it.count(v[i][k])==0)
                    {
                        no++;
                    }
                }
            }
            if(no==0)
            {
                for(auto j:it)
                    cout<<j<<" ";
                
            }
        }
        memset(vis,0,sizeof(vis));
        //for (auto& i : comp) {
           comp.clear();
        //}
        for (auto& i : v) {
           i.clear();
        }
         for (auto& i : vt) {
           i.clear();
        }
        cout<<endl;
        
    }
	return 0;
}
