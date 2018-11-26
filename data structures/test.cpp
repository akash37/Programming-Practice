#include<bits/stdc++.h>
using namespace std;
struct node
{
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
    return root;
}
vector<int> preorder(struct node *root,vector<int>&path)
{
    if(root != NULL)
    {
        path.push_back(root->data);
        preorder(root->left,path);
        preorder(root->right,path);
    }
    return path;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            root = insert(root,a[i]);
        }
        vector<int>path;
        path.clear();
        path = preorder(root,path);
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            cout<<path[i]<<" ";
            if(path[i] != a[i])
                flag = 1;
        }
        if(flag==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    
    }
}