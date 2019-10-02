#include<bits/stdc++.h>
using namespace std;
int n;
int fn(vector<pair<int,int>> f,int i,int v,int k)
{
	//cout<<v<<" ";
	if(v<=k)
	return 0;
	if(i==n)
	return 100000001;
	int a1,a2,a3;
	if(f[i].first!=f[i-1].first){
		//cout<<f[i].first<<" ";
		int t=f[i].first;
		a2=fn(f,i+1,v,k);
		f[i].first=f[i-1].first;
		f[i].second=f[i-1].second;
		a1=fn(f,i+1,v-1,k)+f[i].second;
		//cout<<a1<<" ";
		return min(a1,a2);
		
	}
	else
	{
		//cout<<i<<" ";
		//cout<<f[i-1].first<<" "<<f[i].first<<endl;
		a3=fn(f,i+1,v-1,k);
		return a3;
	}
	//cout<<a1<<" "<<a2<<" "<<a3<<endl;
	//`return min(a1,min(a2,a3));
	
}
int main()
{
  int a[1001],k,t,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector<pair<int,int>> f(n,{0,0});
        j=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        f[0].first=a[0];
        f[0].second=1;
        for(int i=1;i<n;i++)
        {
        	//cout<<i<<" ";
            while(a[i]==a[i-1]&&i<n)
            {
                f[j].first=a[i];
                f[j].second+=1;
                i++;
            }
            j++;
            f[j].first=a[i];
            f[j].second=1;
        }
        //exit(0);
       
        if(a[n-1]==a[n-2])
        j--;
         //cout<<j+1<<endl;
        n=j;
        cout<<fn(f,1,j,k)<<endl;
        /*cout<<j<<endl;
        for(int i=0;i<=j;i++)
        {
            cout<<f[i].first<<" "<<f[i].second<<endl;
        } */
    }
    return 0;
}