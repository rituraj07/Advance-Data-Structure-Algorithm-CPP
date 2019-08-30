#include <bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
	TrieNode* left;
	TrieNode* right;
};
void insert(int n,TrieNode* head)
{
	TrieNode* curr= head;
	for(int i=31;i>=0;i--)
	{
		int b=(n>>i)&1;
		if(b==0)
		{
			if(!curr->left)
			{
				
				curr->left=new TrieNode();
			}
			curr=curr->left;
		}
		else
		{
			if(!curr->right)
			{
				
				curr->right=new TrieNode();
			}
			curr=curr->right;
		}
		
	}
}
int mx(TrieNode* head,int* a,int n)
{
	int m=INT_MIN;
	for(int i=0;i<n;i++)
	{
		TrieNode* curr= head;
        int v=a[i];
		int val=0;
	for(int j=31;j>=0;j--)
	{
		int b=(v>>j)&1;
		if(b==0)
		{
			if(curr->right)
			{val+=pow(2,j);
			curr=curr->right;}
			else
			curr=curr->left;
		}
		else
		{
			if(curr->left)
			{val+=pow(2,j);
			curr=curr->left;}
			else
			curr=curr->right;
		}
	}
	if(val>m)
	m=val;
	}
	return m;
}
int main() {
    int n,a[100001];
	cin>>n;
    TrieNode* head=new TrieNode();
    for(int i=0;i<n;i++)
    {   cin>>a[i];
     //insert(a[i],head);
    }
    int m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int v=a[i];
        for(int j=i;j<n;j++)
        {
            v=v^a[j];
        }
        if(v>m)
            m=v;
    }
    cout<<m;
	return 0;
}