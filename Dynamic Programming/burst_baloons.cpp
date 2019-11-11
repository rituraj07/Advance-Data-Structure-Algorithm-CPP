class Solution {
public:
    int dp[501][501];
    int fn(vector<int>& a,int l,int r)
    {
        
        if(r>=a.size()||l>=a.size())
            return 0;
        if(l<0||r<0)
            return 0;
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int ans=0;
        for(int i=l;i<=r;i++)
        {
            ans=max(ans,fn(a,l,i-1)+(l-1<0?1:a[l-1])*a[i]*(r+1>=a.size()?1:a[r+1])+fn(a,i+1,r));
        }
        return dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        if(nums.empty()) return 0;
        memset(dp,-1,sizeof(dp));
        return fn(nums,0,nums.size()-1);
    }
};