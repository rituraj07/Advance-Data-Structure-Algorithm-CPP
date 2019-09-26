#include <iostream>
using namespace std;
void update(int *bit,int i,int v,int n)
{
	//i++;
	while(i<=n)
	{
		bit[i]+=v;
		i=i+(i&-i);
	}
}
int query(int *bit,int i)
{
	//i++;
	//cout<<"mm ";
	int sum=0;
	while(i>0)
	{
		sum+=bit[i];
		i-=i&(-i);
	}
	return sum;
}
int main() {
	int n,q,l,r;
	int* bit=new int[n+2]();
	int* a=new int[n+2];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		update(bit,i,a[i],n);
	}
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
	//	cout<<r<<" ";
		cout<<query(bit,r)-query(bit,l-1);
	}
	return 0;
}