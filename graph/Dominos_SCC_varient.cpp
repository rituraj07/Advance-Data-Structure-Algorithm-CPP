#include<bits/stdc++.h>
using namespace std;
vector<int> v[100001];
stack<int> st;
int vis[100001];
int dfs(int s)
{
	vis[s]=1;
	for(int i=0;i<v[s].size();i++)
	{
		if(vis[v[s][i]]==0)
		dfs(v[s][i]);
	}
	st.push(s);
}
int dfs2(int s)
{
	vis[s]=1;
	for(int i=0;i<v[s].size();i++)
	{
		if(vis[v[s][i]]==0)
		dfs(v[s][i]);
	}
}
int main()
{
    int t;
    
	cin>>t;
	while(t--)
	{
        //v.clear();
        memset(vis,0,sizeof(vis));
        int a,b,n,e;
		cin>>n>>e;
		while(e--)
		{
			cin>>a>>b;
			v[a].push_back(b);
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				dfs(i);
			}
		}
		int c=0;
		memset(vis,0,sizeof(vis));
		while(!st.empty())
		{
			int i=st.top();
			st.pop();
			if(vis[i]==0)
			{
                c++;
				dfs2(i);
			}
		}
		cout<<c<<endl;
        for(int i=1;i<=n;i++)
            v[i].clear();
		
	}
}