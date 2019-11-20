class Solution {
public:
    int maxProduct(vector<int>& a) {
        if(a.size()==0)
            return 0;
        int curr_max;
        int curr_min=a[0],prev_max=a[0],prev_min=a[0],ans=a[0];
        for(int i=1;i<a.size();i++)
        {
            curr_max=max(prev_max*a[i],max(prev_min*a[i],a[i]));
            curr_min=min(prev_max*a[i],min(prev_min*a[i],a[i]));
            ans=max(ans,curr_max);
            prev_max=curr_max;
            prev_min=curr_min;
        }
        return ans;
    }
};