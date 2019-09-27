#include <bits/stdc++.h>
using namespace std;
int n,t,s,st,v,no,ans,o;
vector<pair<int,int>> a;
int main() {
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>v;
		a.push_back(make_pair(v,i+1));
	}
	sort(a.begin(),a.end());
	int d=a[2].first-a[1].first;
	for(int i=1;i<n-1;i++)
	{
		if(a[i+1].first-a[i].first==d)
		{
			o++;
		}
	}
	if(o==n-2){
	cout<<a[0].second;
	exit(0);}
	o=0;
	d=a[2].first-a[0].first;
	for(int i=2;i<n-1;i++)
	{
		if(a[i+1].first-a[i].first==d)
		{
			o++;
		}
	}
	//cout<<o<<" ";
	if(o==n-3)
	{
		cout<<a[1].second;
			exit(0);
	}
	d=a[1].first-a[0].first;
	for(int i=1;i<n-1;i++)
	{
		if(a[i+1].first-a[i].first!=d)
		{
			no++;
			if(no>1)
			{
				cout<<"-1";
				exit(0);
			}
			ans=a[i+1].second;
			if(i+2<n){
			if(a[i+2].first-a[i].first==d)
			{
				i++;
			}
			else
			{
				cout<<"-1";
				exit(0);
			}}
		}
	}
	cout<<ans;
	return 0;
}