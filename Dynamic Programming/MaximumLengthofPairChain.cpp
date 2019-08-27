class Solution {
    
public:
    static bool comp(vector<int> a,vector<int> b)
    {
        if(a[0]<b[0])
            return true;
        else
            return false;
    }
    int dp[100001];
    int findLongestChain(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),comp);
        dp[0]=1;
        int ans=0;
        for(int i=1;i<v.size();i++)
        {
            int m=0;
            for(int j=0;j<i;j++)
            {
                if(v[j][1]<v[i][0])
                {
                    m=max(m,dp[j]);
                }
            }
            dp[i]=m+1;ans=max(ans,dp[i]);
        }
        return ans;
    }
};