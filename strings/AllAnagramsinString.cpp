class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length())
            return {};
        vector<int> vs(26,0),vp(26,0),ans;
        int i,j=0;;
        
        for(i=0;i<p.length();i++)
        {
            vp[p[i]-'a']++;
            vs[s[i]-'a']++;
        }  
        if(vp==vs)
            ans.push_back(0);
        for(;i<s.length();i++)
        {
            vs[s[j]-'a']--;
            vs[s[i]-'a']++;
            j++;
            if(vp==vs)
                ans.push_back(j);
            
            
        }
        return ans;
    }
};