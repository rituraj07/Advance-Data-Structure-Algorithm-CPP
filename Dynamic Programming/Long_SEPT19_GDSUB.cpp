#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dp[20000][20000],n,k,x=0,ans;
long long v[100001];
map<int,int> mp;
int main() {
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		mp[x]++;
	}
	int i=1;
	for(auto it=mp.begin();it!=mp.end();it++,i++)
	{
	    
	    dp[1][i]=(dp[1][i-1]+it->second)%mod;
	    //ans=(ans+it->second)%mod;
	    v[i]=it->second;
	   // cout<<dp[1][i]<<" ";
	}
	//cout<<endl;
	n=mp.size();
	k=min(k,(int)mp.size());
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			dp[i][j]=(v[j]*dp[i-1][j-1])%mod;
			//ans=(ans+dp[i][j])%mod;
			dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
		//	cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	for(int i=1;i<=k;i++)
	{
	    ans=(ans+dp[i][n])%mod;
	}
	cout<<ans+1<<endl;
	return 0;
}