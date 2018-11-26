#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left,*right;
};

struct node *root = NULL;

struct node * newNode(int key)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
}

struct node *insert(struct node *node,int key)
{
	if(node == NULL)
		return newNode(key);
	else
	{
		if(key<node->data)
			node->left = insert(node->left,key);
		else if(key>node->data)
			node->right = insert(node->right,key);
	}
	return node;
}

void inorderWithRecursion(struct node *node)
{
	if(node)
	{
		inorderWithRecursion(node->left);
		cout<<node->data<<" ";
		inorderWithRecursion(node->right);
	}
}

void preorderWithRecursion(struct node *node)
{
	if(node)
	{
		cout<<node->data<<" ";
		preorderWithRecursion(node->left);
		preorderWithRecursion(node->right);
	}
}

void postorderWithRecursion(struct node *node)
{
	if(node)
	{
		postorderWithRecursion(node->left);
		postorderWithRecursion(node->right);
		cout<<node->data<<" ";
	}
}

void preorder(struct node *node)
{
	stack<struct node *>s;
	s.push(node);
	while(!s.empty())
	{
		struct node *temp = s.top();
		cout<<temp->data<<" ";
		s.pop();
		if(temp->right!=NULL)
			s.push(temp->right);
		if(temp->left!=NULL)
			s.push(temp->left);
	}
}

void inorder(struct node * node)
{
	stack<struct node *>s;
	s.push(node);
	while(!s.empty())
	{
		while(node->left)
		{
			s.push(node->left);
			node = node->left;
		}
		struct node *temp = s.top();
		cout<<temp->data<<" ";
		s.pop();
		if(temp->right)
		{
			s.push(temp->right);
			node = temp->right;
		}
	}
}

void postorder(struct node *node)
{
	if(node == NULL)
		return;
	stack<struct node*>s1;
	stack<struct node*>s2;
	s1.push(node);
	struct node *temp;
	while(!s1.empty())
	{
		temp = s1.top();
		s1.pop();
		s2.push(temp);
		if(temp->left)
			s1.push(temp->left);
		if(temp->right)
			s1.push(temp->right);
	}
	while(!s2.empty())
	{
		struct node *temp1;
		temp1 = s2.top();
		cout<<temp1->data<<" ";
		s2.pop();
	}
}

void postorderUsingOneStack(struct node *node)
{
	stack<struct node*>s;
	struct node *current = node;
	while(current != NULL || !s.empty())
	{
		if(current != NULL)
		{
			s.push(current);
			current = current->left;
		}
		else
		{
			struct node *temp = s.top()->right;
			if(temp == NULL)
			{
				temp = s.top();
				s.pop();
				cout<<temp->data<<" ";
				while(!s.empty() && temp == s.top()->right)
				{
					temp = s.top();
					cout<<temp->data<<" ";
					s.pop();
				}
			}
			else
			{
				current  = temp;
			}
		}
	}
	
}

void levelorder(struct node *node)
{
	queue<struct node*>q;
	q.push(node);
	while(!q.empty())
	{
		struct node *temp;
		temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
}

void leftview(struct node *node,int level,int *maxlevel)
{
	if(node == NULL)
		return;
	if(*maxlevel < level)
	{
		cout<<node->data<<" ";
		*maxlevel = level;
	}
	leftview(node->left,level+1,maxlevel);
	leftview(node->right,level+1,maxlevel);
}

void rightview(struct node *node,int level,int *maxlevel)
{
	if(node == NULL)
		return;
	if(*maxlevel < level)
	{
		cout<<node->data<<" ";
		*maxlevel = level;
	}
	rightview(node->right,level+1,maxlevel);
	rightview(node->left,level+1,maxlevel);
}

void mirror(struct node *node)
{
	if(node == NULL)
		return;
	
	mirror(node->left);
	mirror(node->right);
	struct node *temp;
	temp = node->left;
	node->left = node->right;
	node->right = temp; 
}

void search(struct node *node,int key)
{
	if(node == NULL)
		return;
	if(key < node->data)
		search(node->left,key);
	else if(key > node->data)
		search(node->right,key);
	else if(key == node->data)
		cout<<"ELement Found";
}

int height(struct node *node)
{
	if(node == NULL)
		return -1;
	int leftheight = height(node->left);
	int rightheight = height(node->right);
	return max(leftheight,rightheight) + 1;
}

struct node * LCA(struct node *node,int n1,int n2)
{
	if(node == NULL)
		return NULL;
	if(node->data == n1 || node->data == n2)
		return node;
	struct node *leftLCA = LCA(node->left,n1,n2);
	struct node *rightLCA = LCA(node->right,n1,n2);
	if(leftLCA != NULL && rightLCA != NULL)
		return node;
	else if(leftLCA != NULL && rightLCA == NULL)
		return leftLCA;
	else if(leftLCA == NULL && rightLCA != NULL)
		return rightLCA;
}

int sumOfAllNodes(struct node *node)
{
	if(node == NULL)
		return 0;
	return sumOfAllNodes(node->left) + sumOfAllNodes(node->right) + node->data;
}

int sumofAllLeafNodes(struct node *node)
{
	if(node == NULL)
		return 0;
	if(node->left == NULL && node->right == NULL)
		return node->data;
	return sumofAllLeafNodes(node->left) + sumofAllLeafNodes(node->right);
}

bool rootToLeaf(struct node *node,int n1,vector<int>&path)
{
	if(node == NULL)
		return false;
	path.push_back(node->data);
	if(node->data == n1)
		return true;
	if (rootToLeaf(node->left,n1,path) || rootToLeaf(node->right,n1,path))
		return true;
	path.pop_back();
	return false;
}

void findSum(vector<int>&path)
{
	int sum = 0;
	for(int i=0;i<path.size();i++){
		sum += path[i];
	}
	cout<<sum<<" ";
}

void sumFromRootToLeaf(struct node *node,vector<int>&path)
{
	if(node == NULL)
		return;
	path.push_back(node->data);
	if(node->left == NULL && node->right == NULL){
		findSum(path);
		path.pop_back();
	}
	else
	{
		sumFromRootToLeaf(node->left,path);
		sumFromRootToLeaf(node->right,path);
		path.pop_back();
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		root = insert(root,a[i]);
	}
	postorder(root);
	cout<<endl;
	postorderUsingOneStack(root);
	// int num1,num2;
	// cin>>num1>>num2;
	// struct node * ans = LCA(root,num1,num2);
	// cout<<ans->data<<" ";
	// vector<int>path;
	// bool check1 = rootToLeaf(root,num1,path);
	// bool check2 = rootToLeaf(root,num2,path);
	// cout<<check1<<" "<<check2;
}