class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(k==1)
            return "";
        stack<pair<char,int>> stk;
        int c=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(!stk.empty()){
                //cout<<stk.top().first<<" "<<stk.top().second<<" | ";
            if(s[i]==stk.top().first){
            stk.push({s[i],c+1});
                c=stk.top().second;
            if(stk.top().second==k)
            {
                for(int j=0;j<k;j++)
                stk.pop();
                if(stk.empty())
                c=0;
                else
                c=stk.top().second;    
            }
            }
            else
            {
               stk.push({s[i],1});   
               c=stk.top().second;
            }
            
            }
            else
            {
                stk.push({s[i],1});
                c=stk.top().second;
            }
        }
        string str;
        while(!stk.empty())
        {
            str+=stk.top().first;
            stk.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};