class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        vector<pair<int,int>> g[500];
        int vis[2][n+1];
        memset(vis,0,sizeof(vis));
        vector<vector<int>> cost(n,vector<int>(2,-1));
        for(auto i:r)
        {
            g[i[0]].push_back({i[1],0});
        }
        for(auto i:b)
        {
            g[i[0]].push_back({i[1],1});
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        cost[0]={0,0};
        //int lvl=0;
        while(!q.empty())
        {
            auto[i,c1]=q.front();
            q.pop();
            for(auto [j,c2]:g[i])
            {
                if(cost[j][c2]!=-1||c1==c2) continue;
                cost[j][c2]=cost[i][c1]+1;
                q.push({j,c2});
            }
        }
        vector<int> ans;
        for(auto& i:cost)
        {
            sort(i.begin(),i.end());
            ans.push_back(i[0]!=-1 ? i[0]:i[1]);
        }
        return ans;
    }
};