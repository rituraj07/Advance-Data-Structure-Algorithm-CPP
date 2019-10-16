class Solution {
public:
    int a[1001][1001];
    int maximalSquare(vector<vector<char>>& m) {
        int n=m.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m[0].size();j++)
            {
               
                if(m[i][j]=='0')
                    a[i][j]=0;
                else
                {a[i][j]=1;ans=1;}
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m[0].size();j++)
            {
                if(a[i][j]!=0)
                {
                    a[i][j]=1+min(a[i-1][j],min(a[i][j-1],a[i-1][j-1]));
                    ans=max(ans,a[i][j]);
                }
            }
        }
       /* for(int i=0;i<n;i++)
        {
            for(int j=0;j<m[0].size();j++)
            {
               cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return ans*ans;
    }
};