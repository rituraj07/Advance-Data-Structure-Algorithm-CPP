#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
pair<pair<int,int>,pair<int,int>> fn(pair<int,int> a,pair<int,int> b,pair<int,int> c,pair<int,int> d)
{
	int l=max(min(a.x,b.x),min(c.x,d.x));
	int dw=max(min(a.y,b.y),min(c.y,d.y));
	int r=min(max(a.x,b.x),max(c.x,d.x));
	int u=min(max(a.y,b.y),max(c.y,d.y));
	if(r<=l||u<=dw)
	return {{0,0},{0,0}};
	return {{l,dw},{r,u}};
	
}
long long sq(pair<int,int> a,pair<int,int> b)
{
	long long r=1;
	return r*abs(a.x-b.x)*abs(a.y-b.y);
}
int main() {
	vector<pair<int,int>> p(6);
	for(int i=0;i<6;i++)
	cin>>p[i].x>>p[i].y;
	pair<pair<int,int>,pair<int,int>> a1,a2,a3;
	a1=fn(p[0],p[1],p[2],p[3]);
	a2=fn(p[0],p[1],p[4],p[5]);
	a3=fn(a1.x,a1.y,a2.x,a2.y);
	//cout<<a1.x.x<<" "<<a1.x.y<<"  "<<a1.y.x<<" "<<a1.y.y<<endl;
	long long aw=sq(p[0],p[1]);
	long long aa1=sq(a1.x,a1.y);
	long long aa2=sq(a2.x,a2.y);
	long long aa3=sq(a3.x,a3.y);
	//cout<<aw<<" "<<aa1<<" "<<aa2<<" "<<aa3<<endl;
	if(aw>aa1+aa2-aa3)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	
	return 0;
}