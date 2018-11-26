#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left,*right;
};
struct node *root=NULL;
struct node *newNode(int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node * insert(int key,struct node *Node)
{
    if(Node == NULL){
        return newNode(key);
    }
    if(key < Node->data){
        Node->left = insert(key,Node->left);
    }
    else if(key > Node->data){
        Node->right = insert(key,Node->right);
    }
}

int height(struct node *root){
    if(root == NULL){
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return max(leftheight,rightheight) + 1;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        root = insert(a[i],root);
    }
    int h = height(root);
    cout<<h;
}