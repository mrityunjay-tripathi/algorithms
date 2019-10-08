#include<iostream>
#include<queue>
#include<malloc.h>

using namespace std;

struct node
{
	struct node *left, *right;
	int data;
};

struct node *newNode(int val)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

void levelorder(struct node *root)
{
	if(!root)
		return ;
	queue<node *> Q;
	Q.push(root);
	//Algorithm
	while(!Q.empty())
	{
		struct node *ptr = Q.front();
		cout<<ptr->data<<" ";
		if(ptr->left!=NULL)
			Q.push(ptr->left);
		if(ptr->right!=NULL)
			Q.push(ptr->right);
		Q.pop();
	}
	cout<<endl;
}

int main()
{
	struct node *root = newNode(7);
	root->left = newNode(17);
	root->right = newNode(76);
	root->left->left = newNode(3);
	root->left->right = newNode(54);
	root->right->left = newNode(8);
	root->right->right = newNode(1);
	levelorder(root);
}
