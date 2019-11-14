class Solution {
public:
    map<int,bool> dp;
    bool fn(vector<int> &a,int i,int s)
    {
        if(s==0)
            return true;
        
        if(dp.count(s)>0)
            return dp[s];
        if(i>=a.size())
        {
            return false;    
        }
        if(s-a[i]<0)
            return false;
        dp[s]= fn(a,i+1,s-a[i])|fn(a,i+1,s);
        return dp[s];
    }
    bool canPartition(vector<int>& a) {
        int s=0;
        for(int i=0;i<a.size();i++)
        {
            s+=a[i];
        }
        sort(a.begin(),a.end());
        if(s%2!=0)
            return false;
        s=s/2;
        return fn(a,0,s);
    }
};