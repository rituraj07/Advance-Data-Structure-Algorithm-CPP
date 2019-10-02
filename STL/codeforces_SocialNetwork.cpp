#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long t,n,x,s,k,c;
int main() {
	cin>>n>>k;
	unordered_set<int> s;
	queue<int> q;
	for(int i=0;i<n;i++)
	{
	    
		cin>>x;
		if(s.size()<k)
		{
		    if(s.find(x)==s.end()){
			s.insert(x);
			q.push(x);
		    }
		}
		else
		{
			//set<int>::iterator it=;
			if(s.find(x)==s.end())
			{
				s.erase(q.front());
				q.pop();
				q.push(x);
				s.insert(x);
			}
		}
		//cout<<s.size()<<" ";
	}
	//cout<<endl;
	vector<int> v;
	while(!q.empty())
	{
	    //cout<<q.front()<<" ";
		v.push_back(q.front());
		q.pop();
	}
	cout<<v.size()<<endl;
	for(int i=v.size()-1;i>=0;i--)
	cout<<v[i]<<" ";
	return 0;
}