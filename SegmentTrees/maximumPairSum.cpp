#include<bits/stdc++.h>
using namespace std;
struct p{
    int a1;
    int a2;
};
pair<int,int> mx(int a,int b,int c,int d)
{
    int m1,m2;
    if(a>=max(b,max(c,d)))
    {
        m1=a;
        m2=max(b,max(c,d));
    }
    else if(b>=max(a,max(c,d)))
    {
        m1=b;
        m2=max(a,max(c,d));
    }
    else if(c>=max(b,max(a,d)))
    {
        m1=c;
        m2=max(b,max(a,d));
    }
    else
    {
        m1=d;
        m2=max(b,max(c,a));
    }
    return make_pair(m1,m2);
}
pair<int,int> st(int* a,p* t,int s,int e,int n,int l,int r)
{
	if(e<l||s>r)
	{
		return make_pair(-1,-1);
	}
	if(s>=l&&e<=r)
    {//cout<<t[n]<<endl;
        return make_pair(t[n].a1,t[n].a2);
    }
	
	int m=(s+e)/2;
    pair<int,int> temp1=st(a,t,s,m,n*2,l,r);
     pair<int,int> temp2=st(a,t,m+1,e,n*2+1,l,r);
	return mx(temp1.first,temp1.second,temp2.first,temp2.second);
}
void ut(int* a,p* t,int s,int e,int n,int i,int v)
{
	if(s==e)
	{
		a[i]=v;
		t[n].a1=v;
        t[n].a2=0;
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
    pair<int,int> temp=mx(t[2*n].a1,t[2*n].a2,t[2*n+1].a1,t[2*n+1].a2);
	t[n].a1=temp.first;
    t[n].a2=temp.second;
}
void bt(int* a,p* t,int s,int e,int n)
{
	if(s==e)
	{t[n].a1=a[s];
     t[n].a2=0;
     //cout<<t[n]<<endl;
     return;}
	int m=(s+e)/2;
	bt(a,t,s,m,2*n);
	bt(a,t,m+1,e,2*n+1);
	
	pair<int,int> temp=mx(t[2*n].a1,t[2*n].a2,t[2*n+1].a1,t[2*n+1].a2);
	t[n].a1=temp.first;
    t[n].a2=temp.second;
}

int main() {
    std::ios::sync_with_stdio(false);
    int l,r,ind,v,a[100001],q,n;
    char c;
	cin>>n;
    for(int i=0;i<n;i++)
    {  cin>>a[i];
    // cout<<a[i]<<" ";
    }
    //cout<<endl;
     p* tree=new p[4*n];
	bt(a,tree,0,n-1,1);
   // for(int i=1;i<(2*n);i++)
     //   cout<<tree[i]<<" ";
    cin>>q;
    while(q--)
    {
       // cout<<n<<endl;
        cin>>c;
        if(c=='U')
        {
            cin>>ind>>v;
            ut(a,tree,0,n-1,1,ind-1,v);
        }
        else
        {
            cin>>l>>r;
            pair<int,int> temp=st(a,tree,0,n-1,1,l-1,r-1);
            cout<<temp.first+temp.second<<endl;
        }
        //cout<<endl;
    }
	
	return 0;
}