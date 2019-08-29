/*
2 vs 3
Send Feedback
The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output:
For each query of Type 0 print the value modulo 3.
Constraints:
1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N
Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
1
2
1
*/
#include<bits/stdc++.h>
using namespace std;
int p[100001];
int st(int* arr ,int* t,int s,int e,int n,int l,int r)
{
	if(e<l||s>r)
	{
		return 0;
	}
	if(s>=l&&e<=r)
    {
        return t[n]*p[r-e];
    }
	
	int m=(s+e)/2;
	return (st(arr,t,s,m,n*2,l,r)+st(arr,t,m+1,e,n*2+1,l,r))%3;
}
void ut(int* arr ,int* t,int s,int e,int n,int i,int v)
{
	if(s==e)
	{
		arr[i]=1;
		t[n]=v;
		return;
	}
	int m=(s+e)/2;
	if(i>m)
	{
		ut(arr,t,m+1,e,n*2+1,i,v);
	}
	else
	{
		ut(arr,t,s,m,n*2,i,v);	
	}
    //t[n]=(t[2*n+1]+(p[e-m])*(t[2*n]));
	t[n]=(t[2*n+1]+((p[e-m]%3)*(t[2*n]%3))%3)%3;
}
void bt(int* arr ,int* t,int s,int e,int n)
{
	if(s==e)
	{t[n]=arr[s];
     //cout<<t[n]<<endl;
     return;}
	int m=(s+e)/2;
	bt(arr,t,s,m,2*n);
	bt(arr,t,m+1,e,2*n+1);
	
    //t[n]=(t[2*n+1]+(p[e-m])*(t[2*n]));
	t[n]=(t[2*n+1]+((p[e-m]%3)*(t[2*n]%3))%3)%3;
}
int main() {
    int l,r,ind,v,q,n,j=0,c;
    string a;
	cin>>n;
    cin>>a;
    int* arr = new int[n];
    //cout<<endl;
     for(int i=0;i<a.length();i++){
    if(a[i]=='0'){ arr[i]=0; }
    else{ arr[i]=1; }
  }
	int* tree = new int[4*n];
    p[0]=1;
    for(int i=1;i<100001;i++)
    {
        p[i]=(2*p[i-1])%3;
        //cout<<p[i]<<" ";
    }
	bt(arr,tree,0,n-1,1);
    
    cin>>q;
    while(q--)
    {
        cin>>c;
        if(c==1)
        {
            cin>>ind;
            if(arr[ind]==0)
            {
            ut(arr,tree,0,n-1,1,ind,1);
            }
        }
        else
        {
            cin>>l>>r;
            cout<<st(arr,tree,0,n-1,1,l,r)<<endl;
        }
    }
	
	return 0;
}