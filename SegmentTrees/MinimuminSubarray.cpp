#include<bits/stdc++.h>
using namespace std;
int st(int* a,int* t,int s,int e,int n,int l,int r)
{
	if(e<l||s>r)
	{
		return INT_MAX;
	}
	if(s>=l&&e<=r)
    {//cout<<t[n]<<endl;
        return t[n];}
	
	int m=(s+e)/2;
	return min(st(a,t,s,m,n*2,l,r),st(a,t,m+1,e,n*2+1,l,r));
}
void ut(int* a,int* t,int s,int e,int n,int i,int v)
{
	if(s==e)
	{
		a[i]=v;
		t[n]=v;
		return;
	}
	int m=(s+e)/2;
	if(i>m)
	{
		ut(a,t,m+1,e,n*2+1,i,v);
	}
	else
	{
		ut(a,t,s,m,n*2,i,v);	
	}
	t[n]=min(t[2*n],t[2*n+1]);
}
void bt(int* a,int* t,int s,int e,int n)
{
	if(s==e)
	{t[n]=a[s];
     //cout<<t[n]<<endl;
     return;}
	int m=(s+e)/2;
	bt(a,t,s,m,2*n);
	bt(a,t,m+1,e,2*n+1);
	
	t[n]=min(t[2*n],t[2*n+1]);
}
int main() {
    int l,r,ind,v,a[100001],q,n;
    char c;
	cin>>n>>q;
    for(int i=0;i<n;i++)
    {  cin>>a[i];
    // cout<<a[i]<<" ";
    }
    //cout<<endl;
	int* tree = new int[4*n];
	bt(a,tree,0,n-1,1);
   // for(int i=1;i<(2*n);i++)
     //   cout<<tree[i]<<" ";
    while(q--)
    {
       // cout<<n<<endl;
        cin>>c;
        if(c=='u')
        {
            cin>>ind>>v;
            ut(a,tree,0,n-1,1,ind-1,v);
        }
        else
        {
            cin>>l>>r;
            cout<<st(a,tree,0,n-1,1,l-1,r-1)<<endl;
        }
        //cout<<endl;
    }
	
	return 0;
}