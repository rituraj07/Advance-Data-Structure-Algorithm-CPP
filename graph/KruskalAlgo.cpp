#include <bits/stdc++.h>
using namespace std;
int p[100001];
struct mst{
    int v1;
    int v2;
    int e;
};
bool compare(struct mst a,struct mst b)
{
    return a.e<b.e;
}
void setP(int a,int b)
{
	//p[a]=b;
    while(p[a]!=a)
	{
		a=p[a];
	}
    while(p[b]!=b)
	{
		b=p[b];
	}
    p[a]=b;
    
}
int checkP(int a,int b)
{
	//int pa,pb;
	while(p[a]!=a)
	{
		a=p[a];
	}
	while(p[b]!=b)
	{
		b=p[b];
	}
	if(a==b)
	return 0;
	else
	return 1;
}
int main()
{
  int V, E, tempX, tempY,i;
    struct mst g[10001];
    struct mst a[10001];
  cin >> V >> E;
    for(i=0;i<100001;i++)
    {
    	p[i]=i;
    }
    for(i=0;i<E;i++)
    {
        cin>>g[i].v1>>g[i].v2>>g[i].e;
    }
    sort(g,g+E,compare);
    
    a[0].v1=g[0].v1;a[0].v2=g[0].v2;a[0].e=g[0].e;
    int inc=a[0].v1;
    p[a[0].v2]=a[0].v1;
	int k=1;i=1;
    int c=1;
    cout<<g[0].v1<<" "<<g[0].v2<<" "<<g[0].e<<endl;
    while(c<V-1){
        if(checkP(g[i].v1,g[i].v2))
        {
            cout<<min(g[i].v1,g[i].v2)<<" "<<max(g[i].v1,g[i].v2)<<" "<<g[i].e<<endl;
        	a[k++].v1=g[i].v1;a[k++].v2=g[i].v2;a[k++].e=g[i].e;
        	setP(g[i].v1,g[i].v2);
        	//setP(g[i].v2,inc);
            c++;
        }
        i++;
    }
  return 0;
}
