class MajorityChecker {
public:
    unordered_map<int,vector<int>> m;
    MajorityChecker(vector<int>& arr) {
       for(int i=0;i<arr.size();i++)
           m[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int t) {
        for(std::pair<int, std::vector<int>> i:m)
        {
            if(i.second.size()<t)
                continue;
            std::vector<int>::iterator v1=lower_bound(i.second.begin(),i.second.end(),left);
            std::vector<int>::iterator v2=upper_bound(i.second.begin(),i.second.end(),right);
            if(v2-v1>=t) return i.first;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */