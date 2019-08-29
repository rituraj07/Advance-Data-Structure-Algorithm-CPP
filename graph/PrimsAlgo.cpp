#include <bits/stdc++.h>
using namespace std;
 int n, E, tempX, tempY,v1,v2,wt,g[10001][10001];

int getmv(bool* v,int* w)
{
    int mv=-1;
    for(int i=0;i<n;i++)
    {
        if(!v[i]&&((mv==-1)||(w[i]<w[mv])))
            mv=i;
    }
    return mv;
}
int main()
{
 
  cin >> n >> E;

  for(int i=0;i<E;i++)
  {
      cin>>v1>>v2>>wt;
      g[v1][v2]=wt;
      g[v2][v1]=wt;
  }
    
    int* p = new int[n];
    bool* v = new bool[n]();
    int* w = new int[n];
    
    for(int i=0;i<n;i++)
        w[i]=INT_MAX;
    p[0]=-1;
    w[0]=0;
    
    for(int i=0;i<n-1;i++)
    {
        int mv=getmv(v,w);
        v[mv]=true;
        
        for(int j=0;j<n;j++)
        {
            if(g[mv][j]!=0&&!v[j])
            {
                if(g[mv][j]<w[j])
                {
                    w[j]=g[mv][j];
                    p[j]=mv;
                }
            }
        }
    }
    
    for(int i=1;i<n;i++)
    {
        cout<<min(p[i],i)<<" "<<max(p[i],i)<<" "<<w[i]<<endl;
    }
    
  return 0;
}
