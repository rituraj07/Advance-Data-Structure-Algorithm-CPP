#include <bits/stdc++.h>
using namespace std;
long long n,t,q,s[500001],v,a,b,arr[500001],ao[500001],ae[500001];
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		for(int i=1;i<n;i++)
		{
			cin>>v;
			arr[i]=v;
			if(i%2!=0)
			{
				ao[i]=ao[i-1]+v;
				ae[i]=ae[i-1];
			}
			else
			{
				ae[i]=ae[i-1]+v;
				ao[i]=ao[i-1];
			}
			s[i]+=s[i-1]+v;
			//cout<<s[i]<<" "<<ao[i]<<" "<<ae[i]<<endl;
		}
		while(q--)
		{
			cin>>a>>b;
			//cout<<a<<" "<<b<<endl;
			if(b<a)
			swap(a,b);
			//cout<<a<<" "<<b<<endl;
			if(a==b)
			{
				cout<<"UNKNOWN"<<endl;
			}
			else if(b-a==1)
			{
				cout<<s[b-1]-s[a-1]<<endl;
			}
			else if((b-a)%2!=0)
			{
				if(a%2==0)
				{
					cout<<s[b-1]-s[a-1]-2*(ao[b-1]-ao[a])<<endl;	
				}
				else
				{
					cout<<s[b-1]-s[a-1]-2*(ae[b-2]-ae[a])<<endl;	
				}
				//cout<<s[b-1]-s[a-1]-2*ns<<endl;
				//2*(s[b-3]-s[a])
			}
			else 
			{
				cout<<"UNKNOWN"<<endl;	
			}
		}
		memset(s,0,sizeof(s));
	}
	return 0;
}