#include <bits/stdc++.h>
using namespace std;
int g[10001][10001];

int main()
{
  int n, E,v1,v2,wt, tempX, tempY;
  cin >> n >> E;

  for(int i=0;i<E;i++)
  {
      cin>>v1>>v2>>wt;
      g[v1][v2]=wt;
      g[v2][v1]=wt;
  }
    
    int* d = new int[n];
    bool* v = new bool[n]();
    for(int j=0;j<n;j++){
        d[j]=INT_MAX;
    }
    d[0]=0;
    //v[0]=true;
    for(int i=0;i<n;i++)
    {
        int md=INT_MAX,mn;
        for(int j=0;j<n;j++)
        {
            //cout<<d[j]<<" ";
            if(d[j]<md&&v[j]==false)
            {    mn=j;
                 md=d[j];
            }
        }
        //cout<<endl<<mn<<endl;
        v[mn]=true;
        //cout<<mn<<" ";
        for(int j=0;j<n;j++)
        {
            if(g[mn][j]!=0){
            if(!v[j]&&d[j]>d[mn]+g[mn][j])
                d[j]=d[mn]+g[mn][j];
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        cout<<j<<" "<<d[j]<<endl;
    }

  return 0;
}
