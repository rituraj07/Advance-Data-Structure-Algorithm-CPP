class Solution {
public:
    int maxRepOpt1(string s) {
        vector<pair<char,int>> v;
        int f[26];
        memset(f,0,sizeof(f));
        int c=0;
        char ch;
        int i;
        for(i=0;i<s.length();i++)
        {
            f[s[i]-'a']++;
            if(i==0)
            {
                c=1;
                ch=s[0];
            }
            else
            {
                if(s[i]==s[i-1])
                    c++;
                else
                {
                    v.push_back({s[i-1],c});
                    c=1;
                }
            }
        }
         v.push_back({s[i-1],c});
        int ans=INT_MIN;
        if(v.size()<3)
        {
            for(auto j:v)
            ans=max(ans,j.second);
            //cout<<j.second<<endl;}
            return ans;
        }
        int mx=INT_MIN;
       
        for(int j=0;j<v.size()-2;j++)
        {
           // cout<<mx<<"p ";
            
            if(j+2<=v.size()-1&&v[j].first==v[j+2].first&&v[j+1].second<2)
            {
                if(v[j].second+v[j+2].second==f[v[j].first-'a'])
                {
                    mx=max(mx,(v[j].second+v[j+2].second));
                    
                }
                else
                {
                    mx=max(mx,v[j].second+v[j+2].second+1);
                    //cout<<v[j].second+v[j+2].second<<endl;
                    
                }
            }
            if(v[j].second<f[v[j].first-'a'])
            {
                mx=max(mx,(v[j].second)+1);
                //cout<<
            }
            else
            {
                mx=max(mx,(v[j].second));
            }
        }
        int n=v.size()-1;
        if(v[n].second<f[v[n].first-'a'])
            {
                mx=max(mx,(v[n].second)+1);
                //cout<<
            }
        else
        {
            mx=max(mx,(v[n].second));
        }
        n--;
        if(v[n].second<f[v[n].first-'a'])
            {
                mx=max(mx,(v[n].second)+1);
                //cout<<
            }
        else
        {
            mx=max(mx,(v[n].second));
        }
        return mx;
    }
};