class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& a) {
        if(a.size()==0) return 0;
        int n=a.size();
        int m=a[0].size();
        int dp[101][101][2];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    dp[i+1][j+1][0]=dp[i][j+1][0]+1;
                    dp[i+1][j+1][1]=dp[i+1][j][1]+1;
                    int l1=min(dp[i+1][j+1][0],dp[i+1][j+1][1]);
                    for(int k=l1;k>ans;k--)
                    {
                        //cout<<i+1-k+1<<" "<<j+1-k+1<<endl;
                        int l2=min(dp[i+1-k+1][j+1][1],dp[i+1][j+1-k+1][0]);
                            if(l2>=k)
                            {
                                ans=max(ans,k);
                            }
                    }
                }
                else
                {
                    dp[i+1][j+1][1]=0;
                    dp[i+1][j+1][0]=0;
                }
            }
        }
        return ans*ans;
    }
};