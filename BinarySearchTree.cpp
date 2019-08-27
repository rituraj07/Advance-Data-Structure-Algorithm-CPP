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
Node *insert(Node* root,int key)
{
	if(root==NULL)
	{
		return NewNode(key);
	}
	if(key<root->data)
	{
		root->left=insert(root->left,key);
	}
	else
	root->right=insert(root->right,key);
	
	return root;
	
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
        root=insert(root,key);
		
	}
		cout<<endl;
	inorder(root);
	return 0;
}
