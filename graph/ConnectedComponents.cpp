#include <bits/stdc++.h>
using namespace std;
int g[10001][10001],a,b,i,vis[10001],bk;
queue<int> q;
map<int, int> m;
int main() {
    int v, e;
    cin >> v >> e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        g[a][b]=1;
        g[b][a]=1;
    }
    for(int j=0;j<v;j++){
        if(vis[j]==0){
            vector<int> vt;
            vt.push_back(j);
    q.push(j);
    vis[j]=1;
    while(!q.empty())
    {
        int c=q.front();
        q.pop();
        int i;
        for(i=0;i<v;i++)
        {
            if(g[c][i]==1&&vis[i]==0)
            {
                q.push(i);
                vt.push_back(i);
                vis[i]=1;
                
            }
        }
        
    }
            sort(vt.begin(),vt.end());
            for(int i=0;i<vt.size();i++)
                cout<<vt[i]<<" ";
            cout<<endl;
    }
    }
  return 0;
}
