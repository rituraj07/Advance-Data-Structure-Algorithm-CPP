class Solution {
public:
    int n,m;
    void fn(vector<vector<char>>& a,int i,int j)
    {
        
        if(i<0||j<0||i>=n||j>=m)
            return;
        if(a[i][j]=='0')
            return;
        a[i][j]='0';
        fn(a,i+1,j);
        fn(a,i-1,j);
        fn(a,i,j-1);
        fn(a,i,j+1);
    }
    int numIslands(vector<vector<char>>& a) {
        if(a.size()==0)
            return 0;
         n=a.size();
         m=a[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(a[i][j]=='1')
                {
                    ans++;
                    fn(a,i,j);
                }
            }
        }
        return ans;
    }
};