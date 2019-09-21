#include <iostream>
using namespace std;
long long n,t,a[1000001],x;
int main() {
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cin>>x;
		long long l=0,r=n-1,c1=0,c2=0,b1=0,b2=0;
		while(l<=r)
		{
			if(c1<x*c2)
			{
				c1+=a[l];
				b1++;
				l++;
			}
			else if(c1>x*c2)
			{
				c2+=a[r];
				b2++;
				r--;
			}
			else
			{
			
					if(b1>=b2)
					{
						c1+=a[l];
						b1++;
						l++;
					}
					else
					{
						c2+=a[r];
						b2++;
						r--;
					}
				
			}
			
		}
		
		cout<<b1<<" "<<b2<<endl;
	}
	return 0;
}