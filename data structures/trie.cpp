#include<bits/stdc++.h>
using namespace std;
struct trieNode
{
	struct trieNode *children[26];
	bool isEndOfWord;
};

struct trieNode *getNode()
{
	struct trieNode *pNode = new trieNode;
	pNode->isEndOfWord = false;
	for(int i=0;i<26;i++)
	{
		pNode->children[i] = NULL;
	}
	return pNode;
}

struct trieNode *insert(struct trieNode *root,string key)
{
	struct trieNode *temp = root;
	for(int i=0;i<key.length();i++)
	{
		int index = key[i] - 'a';
		if(temp->children[index] == NULL)
			temp->children[index] = getNode();
		temp = temp->children[index];
	}
	temp->isEndOfWord = true;
}

bool search(struct trieNode *root,string key)
{
	struct trieNode *temp = root;
	for(int i=0;i<key.length();i++)
	{
		int index = key[i] - 'a';
		if(temp->children[index] == NULL)
			return false;
		temp = temp->children[index];
	}
	return (temp != NULL && temp->isEndOfWord);
}

int main()
{
	string keys[] = {"the", "a", "there","answer", "any", "by","bye", "their" };
	int n = sizeof(keys)/sizeof(keys[0]);
	struct trieNode *root = getNode();
	for(int i=0;i<n;i++)
	{
		insert(root,keys[i]);
	}
	search(root,"the")?cout<<"YES ":cout<<"NO";
	search(root,"akash")?cout<<"YES ":cout<<"NO";
}