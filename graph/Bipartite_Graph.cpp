#include <bits/stdc++.h>
using namespace std;
vector<int> v[10001];
int fn(int s)
{
	set<int> st[2];
	queue<int> q;
	st[0].insert(s);
	q.push(s);
	while(!q.empty())
	{
		int n=q.front();
		q.pop();
		int curr;
		if(st[0].count(n)!=0)
		{
			curr=0;
		}
		else
		curr=1;
		for(int i=0;i<v[n].size();i++)
		{
			if(st[0].count(v[n][i])==0&&st[1].count(v[n][i])==0)
			{
				st[1-curr].insert(v[n][i]);
				q.push(v[n][i]);
			}
			else if(st[curr].count(v[n][i])!=0)
			{
				return 0;
			}
		}
	}
	return 1;
}
int main() {
	int n,e,a,b;
	cin>>n>>e;
	while(e--)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout<<fn(0);
	return 0;
}