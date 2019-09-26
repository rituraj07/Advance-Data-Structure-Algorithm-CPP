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
			//curr->children[s[i]-'a']->wt=w;
			curr=curr->children[s[i]-'a'];
		}
		else
		{
			curr=curr->children[s[i]-'a'];
		}
	}
}
TrieNode* query(TrieNode *head,string s)
{
	TrieNode *curr=head;
	for(int i=0;i<s.length();i++)
	{
        //cout<<s[i];
		if(curr->children[s[i]-'a']==NULL)
		return NULL;
		else
		curr=curr->children[s[i]-'a'];
	}
	return curr;
}
void dfs(TrieNode *head,string s,unordered_map<string,int> &m)
{
    int c=0;
    if(m.find(s)!=m.end())
        cout<<s<<endl;
    if(head==NULL)
    {
        return;
    }
    for(int i=0;i<26;i++)
    {
        if(head->children[i]!=NULL)
        {
            dfs(head->children[i],s+(char)('a'+i),m);
        }
    }
    //return;
}
int main() {
	int n,q;
	string s;
    set<string> st;
    unordered_map<string,int> m;
		int w;
	cin>>n;
	TrieNode* head=new TrieNode();
	while(n--)
	{
		cin>>s;
        //st.insert(s);
        m[s]=1;
		insert(head,s,0);	
	}
    
    cin>>q;
	while(q--)
	{
		cin>>s;
		//cout<<s<<endl;
		TrieNode* ans=query(head,s);
        //cout<<ans<<endl;
        if(ans==NULL)
        {
            cout<<"No suggestions"<<endl;
            m[s]=1;
		    insert(head,s,0);
        }
        else
        {
           // cout<<"go"<<endl;
            string t=s;
            dfs(ans,t,m);
            
            
        }
        
	}
	return 0;
}