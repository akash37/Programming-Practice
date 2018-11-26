#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

struct node *newNode(int key)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * insert(struct node *node, int key)
{
	if(node == NULL)
	{
		return newNode(key);
	}
	if (key < node->data)
	{
		node->left = insert(node->left,key);	
	}
	else if (key > node->data)
	{
		node->right = insert(node->right,key);
	}
}

void inorder(struct node *root)
{
	if(root == NULL)
		return;
	else
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if(root == NULL)
		return;
	else
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root == NULL)
		return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}

void levelorder(struct node *root)
{
	struct node *temp;
	queue<struct node*> q;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
	}
}

void search(struct node *node,int key)
{
	if(node == NULL)
	{
		cout<<"Key Not Found";
		return;
	}
	if(node->data == key)
	{
		cout<<"Found the key";
		return;
	}
	if(key < node->data)
	{ 
		search(node->left,key);
	}
	else
	{
		search(node->right,key);
	}
}

void topview(struct node *root)
{

}

void leftview(struct node *root)
{
	struct node *temp;
	queue<struct node*>q;
	q.push(root);
	q.push(NULL);
	cout<<root->data<<" ";
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp == NULL && !q.empty())
		{
			cout<<q.front()->data<<" ";
			q.push(NULL);
		}
		if(temp != NULL)
		{
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
	}
}

void rightview(struct node *root)
{
	struct node *curr,*prev;
	queue<struct node *>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		prev = curr;
		curr = q.front();
		q.pop();
		if(curr == NULL && !q.empty())
		{
			q.push(NULL);
			cout<<prev->data<<" ";
		}
		if(curr != NULL)
		{
			if(curr->left != NULL)
				q.push(curr->left);
			if(curr->right != NULL)
				q.push(curr->right);
		}
	}
	cout<<prev->data<<" ";
}

void numberoflevels(struct node *root)
{
	struct node *temp;
	queue<struct node *>q;
	q.push(root);
	q.push(NULL);
	int level = 1;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp == NULL && !q.empty())
		{
			level++;
			q.push(NULL);
		}
		if(temp != NULL)
		{
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
		}
	}
	cout<<"Number of Levels is " << level << endl;
}

void maxwidthoftree(struct node *root)
{
	struct node *temp;
	queue<struct node *>q;
	q.push(root);
	int width = 0;
	while(!q.empty())
	{
		int w = q.size();
		width = max(width,w);
		temp = q.front();
		q.pop();
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
	}
	cout<<"Maximum Width of Tree is "<<width<<endl;
}

int heightoftree(struct node *root)
{
	if(root == NULL)
	{
		return -1;
	}
	int leftheight = heightoftree(root->left);
	int rightheight = heightoftree(root->right);
	return max(leftheight,rightheight) + 1;
}

int Add(struct node *root){
	if(root == NULL)
		return 0;
	else{
		return Add(root->left) + Add(root->right) + root->data;
	}
}

bool printAncestors(struct node *root,int target)
{
	if(root == NULL)
		return 0;
	if(root->data == target)
		return 1;
	if(printAncestors(root->left,target) || printAncestors(root->right,target))
	{
		cout<<root->data<<" ";
		return 1;
	}
	return 0;
}

struct node *LCA(struct node *root,int n1,int n2){
	if(root == NULL)
		return NULL;
	else if(root->data == n1 || root->data == n2)
		return root;
	struct node *leftLCA = LCA(root->left,n1,n2);
	struct node *rightLCA = LCA(root->right,n1,n2);
	if (leftLCA != NULL && rightLCA != NULL)
		return root;
	else if(leftLCA != NULL && rightLCA == NULL)
		return leftLCA;
	else if(leftLCA == NULL && rightLCA != NULL)
		return rightLCA;
}

void findSum(vector<int>&path){
	int sum = 0;
	for(int i=0;i<path.size();i++){
		sum+=path[i];
	}
	cout<<sum<<" ";
}

void RootToLeaf(struct node *node,vector<int>&path){
	if(node == NULL)
		return;
	path.push_back(node->data);
	if(node->left == NULL && node->right == NULL)
		findSum(path);
	RootToLeaf(node->left,path);
	RootToLeaf(node->right,path);
	path.pop_back();
}

int main()
{
	int n;
	cin>>n;
	int num;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		root = insert(root,num);
	}
	vector<int>path;
	RootToLeaf(root,path);
}