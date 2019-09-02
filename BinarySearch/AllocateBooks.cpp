int ch(vector<int> &a,int p)
{
    int n=0,s=0;
    for(int i=0;i<a.size();i++)
    {
        if(s+a[i]<=p)
        s+=a[i];
        else
        {
            n++;
            s=a[i];
        }
        
    }
    return n+1;
}
int Solution::books(vector<int> &A, int B) {
    if(B>A.size()) return -1;
    int s=0,mx=0;
    for(int i=0;i<A.size();i++)
    {
        s+=A[i];
        mx=max(mx,A[i]);
    }
    int l=1,r=s,pm;
    while(l<=r)
    {
        //cout<<l<<" "<<r<<endl;
        if(l==r) break;
        int m=(l+r)/2;
        
        //cout<<m<<" "<<ch(A,m)<<endl;
        if(ch(A,m)<=B)
        {if(m<mx)
        return mx;pm=m;r=m;}
        else
        l=m+1;
    }
    if(ch(A,l)<=B)
    return l;
    return pm;
}
