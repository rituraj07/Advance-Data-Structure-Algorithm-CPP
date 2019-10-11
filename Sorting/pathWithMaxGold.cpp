class Solution {
public:
    int vis[101][101];
    int getmax(vector<vector<int>>& a,int i,int j)
    {
        if(i<0||i>=a.size()||j<0||j>=a[0].size()||a[i][j]==0)
            return 0;
        vis[i][j]=1;
        int mx=0;
        if(i>0&&a[i-1][j]!=0&&vis[i-1][j]==0)
            mx=max(mx,getmax(a,i-1,j));
        if(i<a.size()-1&&a[i+1][j]!=0&&vis[i+1][j]==0)
            mx=max(mx,getmax(a,i+1,j));
        if(j>0&&a[i][j-1]!=0&&vis[i][j-1]==0)
            mx=max(mx,getmax(a,i,j-1));
        if(j<a[0].size()-1&&a[i][j+1]!=0&&vis[i][j+1]==0)
            mx=max(mx,getmax(a,i,j+1));
        vis[i][j]=0;
        return mx+a[i][j];
    }
    int getMaximumGold(vector<vector<int>>& a) {
        
        int mx=0;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[0].size();j++)
            {
                if(a[i][j]!=0)
                {
                    //cout<<i<<" "<<j<<" ";
                    vis[i][j]=1;
                    mx=max(mx,getmax(a,i,j));
                    vis[i][j]=0;
                }
            }
        }
        return mx;
    }
};