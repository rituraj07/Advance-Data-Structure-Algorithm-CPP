#include <bits/stdc++.h>
using namespace std;
class queryA{
   public:
    int l,r,ind;
};
bool comp(queryA a,queryA b)
{
    return a.r<b.r;
}

void update(int* bit,int v,int i,int n)
{
    while(i<=n)
    {
        bit[i]+=v;
        i+=i&(-i);
    }
}
int query(int* bit,int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&(-i);
    }
    return s;
}
int main()
{
    queryA qa[200001];
    int bit[100001],a[100001],n,q;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>qa[i].l>>qa[i].r;
        qa[i].ind=i;
    }
    sort(qa,qa+q,comp);
    int t=0,k=0,ans[100001],last[1000001];
    memset(last,-1,sizeof(last));
    for(int i=1;i<=n;i++)
    {
        if(last[a[i]]!=-1)
        {
                update(bit,-1,last[a[i]],n);
        }
        else
        {
            t++;
        }
        update(bit,1,i,n);
        last[a[i]]=i;
        //cout<<query(bit,i)<<" ";
        while(k<q&&qa[k].r==i)
        {
            //cout<<t<<" "<<query(bit,qa[k].l-1)<<" ";
            ans[qa[k].ind]=t-query(bit,qa[k].l-1);
            k++;
        }
        
    }
    for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;
    return 0;
}
