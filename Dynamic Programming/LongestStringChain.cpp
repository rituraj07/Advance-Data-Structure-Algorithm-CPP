class Solution {
public:
    static bool comp(string s1,string s2)
    {
        return s1.length()<s2.length();
    }
    int dp[100001];
    bool isValid(string s1,string s2)
    {å
        string t;
        for(int i=0;i<s1.length();i++)
        {
            if(i==0)
            {
                t=s1.substr(1);
            }
            else if(i==s1.length()-1)
            {
                t=s1.substr(0,s1.length()-1);
            }
            else
            {
                t=s1.substr(0,i)+s1.substr(i+1);
            }
            if(t==s2) return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int ans=0;
        dp[0]=1;
        for(int i=1;i<words.size();i++)
        {
            int m=0;
            for(int j=0;j<i;j++)
            {
                if(words[i].length()==1+words[j].length())
                {
                    if(isValid(words[i],words[j]))
                    {
                        m=max(m,dp[j]);
                        
                    }
                }
                //dp[i]=dp[j]+1;
            }
            dp[i]=m+1;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};