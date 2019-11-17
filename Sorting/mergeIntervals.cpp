class Solution {
public:
    static bool compf(vector<int> a,vector<int> b)
    {
        if(a[0]<b[0]) return true;
        else if(a[0]==b[0])
        {
            if(a[1]<b[1]) return true;
        }
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& a) {
        
        vector<vector<int>> ans;
        int n=a.size();
        if(n==0)
            return {};
        sort(a.begin(),a.end(),compf);
        int mx=a[0][0];
        for(int i=0;i<n;)
        {
            mx=a[i][0];
            int s=a[i][0];
            //cout<<s<<" ";
            while(i<n&&mx>=a[i][0])
            {
                mx=max(mx,a[i][1]);
                i++;
            }
            //cout<<i<<" ";
            ans.push_back({s,max(a[i-1][1],mx)});
            
        }
        return ans;
    }
};