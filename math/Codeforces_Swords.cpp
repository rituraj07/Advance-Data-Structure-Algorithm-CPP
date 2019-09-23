#include <bits/stdc++.h>
using namespace std;
long long hcf(long long a,long long b)
{
	if(b==0) return a;
	return hcf(b,a%b);
}
long long n,h,m=INT_MIN,m2=INT_MIN,a[200001];
int main() {
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		m=max(m,a[i]);
		
	}
	long long c=0,s=0,h;
	for(int i=0;i<n;i++)
	{
		a[i]=m-a[i];
		if(c==0&&a[i]!=0)
		{h=a[i];
			c++;
		}
		else if(a[i]!=0)
		{
			h=hcf(h,a[i]);
		}
		//cout<<a[i]<<" ";
		s+=a[i];
	}
	//cout<<endl;
	cout<<s/h<<" "<<h<<endl;
	return 0;
}