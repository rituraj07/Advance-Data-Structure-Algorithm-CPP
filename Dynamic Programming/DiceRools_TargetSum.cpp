class Solution {
public:
    int dp[1001][1001];
    int fn(int d,int f,int t)
    {
        if(d==0&&t==0)
        {
            return 1;
        }
        if(d<=0||t<=0)
        {
            return 0;
        }
        if(dp[d][t]!=-1) return dp[d][t];
        int a=0;
        for(int i=1;i<=f;i++)
        {
            a=(a%1000000007+fn(d-1,f,t-i)%1000000007)%1000000007;
        }
        dp[d][t]= a%1000000007;
        return a%1000000007;
    }
    int numRollsToTarget(int d, int f, int t) {
        memset(dp,-1,sizeof(dp));
        return fn(d,f,t);
    }
};