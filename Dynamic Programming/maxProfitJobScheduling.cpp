class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b)
    {
        if(a.first==b.first)
         return a.second<b.second;
        return a.first<b.first;
    }
    int fn(vector<int>& st, vector<int>& et, vector<int>& p,int i,int n,int s,map<pair<int,int>,int> &m)
    {
        if(i>=n)
            return 0;
        if(i==n-1&&s<st[i])
            return p[i];
        if(m.find({i,s})!=m.end())
            return m[{i,s}];
        if(s<=st[i])
            { 
                m[{i,s}]=max(fn(st,et,p,i+1,n,et[i],m)+p[i],fn(st,et,p,i+1,n,s,m));
            return m[{i,s}];
            }
        else
        {
            m[{i,s}]=fn(st,et,p,i+1,n,s,m);
            return m[{i,s}];
        }
        
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,pair<int,int> > >time;
        for(int i=0;i<startTime.size();i++)
            time.push_back(make_pair(endTime[i],make_pair(startTime[i],profit[i])));
        sort(time.begin(),time.end());
        for(int i=0;i<profit.size();i++)
        {
            startTime[i]=time[i].second.first;
            endTime[i]=time[i].first;
            profit[i]=time[i].second.second;
        }
        map<pair<int,int>,int> m;
        return fn(startTime,endTime,profit,0,profit.size(),-1,m);
        
    }
};