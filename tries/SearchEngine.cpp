#include <bits/stdc++.h>
using namespace std;
class TrieNode{
	public:
	int wt;
	TrieNode** children;
	//TrieNode *a,*b,*c,*d,*e,*f,*g,*h,*i,*j,*k,*l,*m,*n,*o,*p,*q,*r,*s,*t,*u,*v,*w,*x,*y,*z;
	TrieNode()
	{
		children=new TrieNode*[26];
		for(int i=0;i<26;i++)
		children[i]=NULL;
		wt=0;
	}
	
};
void insert(TrieNode *head,string s,int w)
{
	TrieNode *curr=head;
	for(int i=0;i<s.length();i++)
	{
		if(curr->children[s[i]-'a']==NULL)
		{
			curr->children[s[i]-'a']=new TrieNode();
			curr->children[s[i]-'a']->wt=w;
			curr=curr->children[s[i]-'a'];
		}
		else
		{
			if(curr->children[s[i]-'a']->wt<w)
			{
				curr->children[s[i]-'a']->wt=w;
			}
			curr=curr->children[s[i]-'a'];
		}
	}
}
int query(TrieNode *head,string s)
{
	TrieNode *curr=head;
	for(int i=0;i<s.length();i++)
	{
		if(curr->children[s[i]-'a']==NULL)
		return -1;
		else
		curr=curr->children[s[i]-'a'];
	}
	return curr->wt;
}
int main() {
	int n,q;
	string s;
		int w;
	cin>>n>>q;
	TrieNode* head=new TrieNode();
	while(n--)
	{
		cin>>s>>w;
		insert(head,s,w);	
	}
	while(q--)
	{
		cin>>s;
		//cout<<s<<endl;
		cout<<query(head,s)<<endl;
	}
	return 0;
}