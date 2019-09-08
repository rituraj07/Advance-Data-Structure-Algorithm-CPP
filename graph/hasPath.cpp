#include <bits/stdc++.h>
using namespace std;
int g[10001][10001],a,b,i,vis[10001];
queue<int> q;
int main() {
    int v, e;
    cin >> v >> e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        g[a][b]=1;
        g[b][a]=1;
    }
    cin>>a>>b;
    
    q.push(a);
    vis[a]=1;
    while(!q.empty())
    {
        int c=q.front();
        if(c==b)
        {
            cout<<"true";
            exit(0);
        }
        q.pop();
        for(int i=0;i<v;i++)
        {
            if(g[c][i]==1&&vis[i]==0)
            {
                q.push(i);
                vis[i]=1;
            }
        }
    }
    
    cout<<"false";
            exit(0);
  return 0;
}
