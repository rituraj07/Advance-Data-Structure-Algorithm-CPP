class Solution {
public:
    long long hcf(long long a,long long b)
    {
        if(b==0) return a;
        return hcf(b,a%b);
    }
    long long lcm(long long a,long long b)
    {
        long long x=1;
        return (a*b)/hcf(a,b);   
    }
    int fn(long long a,long long b,long long c,long long n)
    {
        int cn=0;
        cn+=n/a;
        cn+=n/b;
        cn+=n/c;
        cn-=n/lcm(a,b);
        cn-=n/lcm(a,c);
        cn-=n/lcm(b,c);
        cn+=n/lcm(a,lcm(b,c));
        return cn;
    }
    int nthUglyNumber(long long n, long long a, long long b, long long c) {
        
        long long l=1,r=2000000000,m,ans,x;
        while(l<=r)
        {
            m=(l+r)/2;
            ans=fn(a,b,c,m);
            if(ans==n)
            {
                x=m;
                r--;
            }
            else if(ans<n)
            {
                l=m+1;
            }
            else
            {
                r=m;
            }
        }
        return x;
        
    }
};