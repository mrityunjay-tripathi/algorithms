#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
	struct node *left;
	struct node *right;
	int data;
};

struct node *NewNode(int val)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node *insert(struct node *node, int val)
{
	if (!node)
	{
		return NewNode(val);
	}
	else
	{
		if(val<=node->data)
			node->left = insert(node->left, val);
		else if (val > node->data)
		{
			node->right = insert(node->right, val);
		}
	}
	return node;
}

struct node *delete_node(struct node *root, int val)
{
	if(!root)
		return root;
	else if (val < root->data)
		root->left = delete_node(root->left, val);
	else if (val > root->data)
		root->right = delete_node(root->right, val);
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left==NULL)
		{
			struct node *temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right ==NULL)
		{
			struct node *temp = root;
			root = root->left;
			free(temp);
		}
		else
		{
			struct node *temp = root->right;
			while(temp->left!=NULL)
			{
				temp = temp->left;
			}
			root->data = temp->data;
			root->right = delete_node(root->right, temp->data);
		}
	}
	return root;
}

bool search(struct node *node, int val)
{
	if(!node)
		return 0;
	else if (val < node->data)
		return search(node->left, val);	
	else if (val > node->data)
		return search(node->right, val);
	else
		return 1;
}

int max(int a,int b)
{
	if (a>=b)
		return a;
	return b;
}

int lowestCommonAncestor(struct node *root, int val1, int val2)
{
	if (!root)
		return -999;
	else
	{
		if(val1<= root->data && val2 > root->data || val2<= root->data && val1 > root->data)
			return root->data;
		else if(root->data > max(val1, val2))
			return lowestCommonAncestor(root->left, val1, val2);
		else
			return lowestCommonAncestor(root->right, val1, val2);
	}
}

void inorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if(root)
	{
		printf("%d ", root->data);
		inorder(root->left);
		inorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		inorder(root->right);
		printf("%d ", root->data);
	}
}

int max_of_array(int arr[], int size)
{
	int max = arr[0];
	for(i = 0; i<size; ++i)
	{
		if(max < arr[i])
			max = arr[i];
	}
	return max;
}

int BT_arr[100];
int i = -1;
int elements_in_BT(struct node *node)
{
	elements_in_BT(node->left);
	BT_arr[++i] = node->data;
	elements_in_BT(node->right);
}

bool isBST(struct node *root)
{
	if (!root)
		return 1;
	else if (root->left!=NULL)
	{
		max_left = find_max_in_BT(root->left);
		if (max_left > root->data)
			return 0;
	}
	else if (root->right!=NULL)
	{
		min_right = find_min_in_BT(root->right);
		if(min_right < root->data)
			return 0;
	}
	return isBST(root->left) && isBST(root->right);
}


int main()
{
	struct node *root = NULL;
	root = insert(root, 34);
	root = insert(root, 62);
	root = insert(root, 14);
	root = insert(root, 7);
	root = insert(root, 22);
	root = insert(root, 12);
	root = insert(root, 48);
	root = insert(root, 42);
	root = insert(root, 51);
	inorder(root);
	printf("\n");
	int val1 = 12, val2 = 22;
	int lca = lowestCommonAncestor(root, val1, val2);
	printf("Lowest common ancestor of %d and %d is : %d\n", val1, val2, lca);	
	//postorder(root);
	//printf("\n");
}




