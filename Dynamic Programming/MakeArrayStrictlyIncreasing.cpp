class Solution {
public:
    
    int fn(vector<int> &a1,int n,vector<int> &a2,int prev,map<pair<int,int>,int> &m)
    {
        if(n>=a1.size())
        {
            return 0;
        }
        int ans=INT_MAX/2;
        if(m.find({n,prev})!=m.end())
            return m[{n,prev}];
        int f=upper_bound(a2.begin(),a2.end(),prev)-a2.begin();
        if(a1[n]>prev)
        {
            ans=min(ans,fn(a1,n+1,a2,a1[n],m));
        }
        if(f<a2.size())
        {
            ans=min(ans,fn(a1,n+1,a2,a2[f],m)+1);
        }
         m[{n,prev}]=ans;
        return ans;
        
        
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        map<pair<int,int>,int> m;
        sort(arr2.begin(),arr2.end());
        int ans=fn(arr1,0,arr2,INT_MIN,m);
        if(ans>=INT_MAX/4)
            return -1;
        return ans;
    }
};