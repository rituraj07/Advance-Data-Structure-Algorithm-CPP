#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
Node * NewNode(int key)
{
	Node *node=new Node;
	node->data=key;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void insertbt(Node *root,int key)
{
	
	queue<struct Node*> q;
	q.push(root);
	//return;
	while(!q.empty())
	{
		struct Node *t=q.front();
		q.pop();
		if(t->left==NULL)
		{
			//cout<<"l"<<" ";
			t->left= NewNode(key);
			break;
		}
		else
		{
			q.push(t->left);
		}
		if(t->right==NULL)
		{
			//cout<<"r"<<" ";
			t->right=NewNode(key);
			break;
		}
		else
		{
			q.push(t->right);
		}
	}
}
void inorder(Node *node)
{
	if(node==NULL)
	return;
	
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}
int main() {
	// your code goes here
		Node* root = NULL;
	//Node* root = NewNode(1); 
	int keys[] = { 10, 20, 8, 12, 16, 25 };
 
	for (int key : keys)
	{
		insertbt(root,key);
	}
	cout<<endl;
	inorder(root);
	return 0;
}
