#include <bits/stdc++.h>
using namespace std;
long long as[26],ar[26],bs[26],br[26];
string s,r;
long long a,b,t;
int main() {
	cin>>t;
	while(t--)
	{
		memset(as,0,sizeof(as));
		memset(ar,0,sizeof(ar));
		memset(br,0,sizeof(br));
		memset(bs,0,sizeof(bs));
		string res;
		char g;
		int no=0,got=0;
		cin>>s>>r;
		for(int i=0;i<s.length();i++)
		{
			if((i>0&&got==0)&&s[i]!=s[i-1])
			{
				got++;
				g=s[i];
			}
			as[s[i]-'a']++;
		}
		for(int i=0;i<r.length();i++)
		{
			bs[r[i]-'a']++;
		}
		for(int i=0;i<26;i++)
		{
			if(as[i]>bs[i])
			no++;
			bs[i]-=as[i];
			//cout<<as[i]<<" "<<bs[i]<<endl;
		}
		if(no)
		{
			cout<<"Impossible"<<endl;
		}
		else
		{
			
			int x=s[0]-'a';
			if((g-'a')<x)
			x--;
			for(int i=0;i<=x;i++)
			{
				//cout<<bs[i]<<" ";
				while(bs[i]--)
				{
					//cout<<bs[i]<<" ";
					cout<<char(i+'a');
				}
			}
			cout<<s;
			for(int i=x+1;i<26;i++)
			{
				while(bs[i]--)
				{
					//cout<<bs[i]<<" ";
					cout<<char(i+'a');
				}
			}
			cout<<endl;
		}
		
	}
	return 0;
}