class Solution {
public:
    int dp[100001];
    int fn(int n)
    {
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,fn(n-i)*i);
        }
        dp[n]=ans;
        
        return ans;
    }
    int integerBreak(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        memset(dp,-1,sizeof(dp));
        return fn(n);
    }
};