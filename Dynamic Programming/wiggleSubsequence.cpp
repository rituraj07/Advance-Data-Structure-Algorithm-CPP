class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
       if(a.size()<2)
           return a.size();
        int u=1,d=1;
        for(int i=1;i<a.size();i++)
        {
            if(a[i]>a[i-1])
                u=d+1;
            else if(a[i]<a[i-1])
                d=u+1;
        }
        return max(u,d);
    }
};