class Solution {
public:
    int dp[1001][1001];
    int fn(int n,int c,int ans)
    {
        if(ans>n)
            return INT_MAX-100001;
        if(ans==n) return 0;
        if(dp[c][ans]!=-1)
            return dp[c][ans];
        int a;
        if(c==ans)
        {
            dp[c][ans]= fn(n,c,c+ans)+1;
            return dp[c][ans];
        }
        else
        {dp[c][ans]= min(fn(n,ans,ans),fn(n,c,c+ans))+1;
         return dp[c][ans];}
    }
    
    int minSteps(int n) {
        memset(dp,-1,sizeof(dp));
        if(n==1)
            return 0;
        if(n==2)
            return 2;
        return 2+fn(n,1,2);
        
    }
};