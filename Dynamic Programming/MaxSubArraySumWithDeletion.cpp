class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n=a.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,a[i]);
        }
        if(mx<0)
            return mx;
        //return 0;
        int *f=new int[n];
        int *b=new int[n];
        f[0]=a[0];
        mx=INT_MIN;
        for(int i=1;i<n;i++)
        {
            f[i]=max(a[i],a[i]+f[i-1]);
        }
        b[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            b[i]=max(a[i],b[i+1]+a[i]);
        }
        mx=(f[0],b[0]);
        for(int i=1;i<n-1;i++)
        {
            mx=max(mx,max(f[i-1]+b[i+1],max(f[i],b[i])));
        }
        mx=max(mx,max(f[n-1],b[n-1]));
        return mx;
    }
};