#include <bits/stdc++.h>
using namespace std;
int p[2000003],ps[2000003],m[2000003];
int main() {
	string s;
	int n,a[200001];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		m[a[i]]=i;
	}
	cin>>s;
	//cout<<s<<endl;
	ps[0]=0;
	int i;
	for(i=0;i<s.length();i++)
	{
		//cout<<"p";
		ps[i+1]=ps[i]+(s[i]-48);
		//cout<<ps[i+1]<<" ";
	}
	int ans=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=i+1)
		{
			int oi=m[i+1];
			if(ps[oi]-ps[i]<oi-i)
			{
				
				ans=0;
				break;
			}
		}
	}
	if(ans==1)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	return 0;
}