class Solution {
public:
   
    int maxDistance(vector<vector<int>>& g) {
        int n=g.size();
        queue<pair<int,int>> q,q1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]==1)
                {
                    q.push({i-1,j});q.push({i+1,j});q.push({i,j+1});q.push({i,j-1});
                }
            }
        }
        int step=0;
        while(!q.empty())
        {
            step++;
            while(!q.empty())
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i>-1&&i<n&&j>-1&&j<n&&g[i][j]==0)
                {
                    g[i][j]=step;
                    q1.push({i-1,j});q1.push({i+1,j});q1.push({i,j+1});q1.push({i,j-1});
                }
            }
            swap(q1,q);
        }
        return step==1?-1:step-1;
        //return step;
    }
};