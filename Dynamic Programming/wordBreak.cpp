class Solution {
public:
    bool fn(string &s,vector<string>& v,int i,string w,map<pair<int,string>,bool> &m)
    {
        //cout<<w<<" ";
        if(i==s.length())
        {
            if(find(v.begin(),v.end(),w)!=v.end())
                return true;
            return false;
        }
        if(m.find({i,w})!=m.end())
            return m[{i,w}];
        bool ans=false;
        string str="";
        str+=s[i];
        if(find(v.begin(),v.end(),w)!=v.end())
        {
            ans=ans|fn(s,v,i+1,str,m)|fn(s,v,i+1,w+s[i],m);
        }
        else
        {
            ans=ans|fn(s,v,i+1,w+s[i],m);
        }
        return m[{i,w}]=ans;
    }
    bool wordBreak(string s, vector<string>& v) {
        map<pair<int,string>,bool> m;
        return fn(s,v,0,"",m);
    }
};