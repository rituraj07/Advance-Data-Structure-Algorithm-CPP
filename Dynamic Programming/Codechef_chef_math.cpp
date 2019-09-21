#include <iostream>
using namespace std;
long long dp[1000001],a[1000001],m=1e9+7;
long long fact(long long n)
{
	dp[n]=(n*dp[n-1])%m;
	return dp[n];
}
int main() {
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
	int t,n;
	a[1]=1;
	dp[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		a[i]=(a[i-1]*fact(i))%m;
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<a[n]<<"\n";
	}
	return 0;
}


//4
// 1 2 2 2 3 3 4
// 1
// 2
// 2 3
// 2 3 4