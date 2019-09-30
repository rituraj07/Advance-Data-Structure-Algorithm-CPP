#include<bits/stdc++.h>
using namespace std;
struct road{
    int s,d,w;
};
bool comp(struct road a,struct road b)
{
    return a.w<b.w;
}
int p[100001];
int checkParent(int a,int b)
{
    while(p[a]!=a)
        a=p[a];
    while(p[b]!=b)
        b=p[b];
    if(a==b) 
        return 0;
    return 1;
}
void setParent(int a,int b)
{
    while(p[a]!=a)
        a=p[a];
    while(p[b]!=b)
        b=p[b];
    p[b]=a;
}
int main()
{
    long long t,n,m,aw,ans,j=0;
    struct road v[100001];
	cin>>t;
    while(t--)
    {
        j++;
        ans=0;
        cin>>n>>m>>aw;
        for(int i=0;i<=n;i++)
            p[i]=i;
        for(int i=0;i<m;i++)
        {
            cin>>v[i].s>>v[i].d>>v[i].w;
        }
        sort(v,v+m,comp);
    
        for(int i=0;i<m;i++)
        {
            if(v[i].w<aw&&checkParent(v[i].s,v[i].d))
            {
                ans+=v[i].w;
                setParent(v[i].s,v[i].d);
            }
        }
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(i==p[i])
            {
                c++;  
                ans+=aw;
            }
        }
        cout<<"Case #"<<j<<": "<<ans<<" "<<c<<endl;
    }
	return 0;
}
