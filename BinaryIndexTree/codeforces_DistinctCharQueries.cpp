#include <iostream>
using namespace std;
int t,n,BIT[26][100001],q,c,l,r;
void update(int *BIT,int ind,int v)
{
	ind++;
	while(ind<=n)
	{
		BIT[ind]+=v;
		ind=ind+(ind&(-ind));
	}
}
int query(int *BIT,int ind)
{
	int ans=0;
	while(ind>0)
	{
		ans+=BIT[ind];
		ind=ind-(ind&(-ind));
	}
	return ans;
}
int main() {
	string s;
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++)
	{
		update(BIT[s[i]-'a'],i,1);
	}
	cin>>q;
	while(q--)
	{
		cin>>c;
		//cout<<c<<endl;
		if(c==1)
		{
			int p;
			char ch;
			cin>>p>>ch;
			p--;
			update(BIT[s[p]-'a'],p,-1);
			s[p]=ch;
			update(BIT[s[p]-'a'],p,1);
		}
		else
		{
			cin>>l>>r;
			int ans=0;
			for(int i=0;i<26;i++)
			{
			    //cout<<query(BIT[i],r)<<endl;
				if((query(BIT[i],r)-query(BIT[i],l-1))>0)
				ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}