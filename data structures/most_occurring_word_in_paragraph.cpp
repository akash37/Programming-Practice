#include<bits/stdc++.h>
using namespace std;
struct Trie
{
	string key;
	int cnt;
	map<char,Trie*>mp;
};

Trie* getNode()
{
	Trie* node = new Trie;
	node->cnt = 0;
	return node;
}

void insert(Trie* &root,string &str)
{
	Trie* temp = root;
	for(int i=0;i<str.length();i++)
	{
		char x = str[i];
		if(temp->mp.find(x) == temp->mp.end())
			temp->mp[x] = getNode();
		temp = temp->mp[x];
	} 
	temp->key = str;
	temp->cnt += 1;
}

bool preorder(Trie* temp, int& maxcnt, string& key)
{
    if (temp == NULL)
        return false;
 
    for (auto it : temp->mp) {
        if (maxcnt < it.second->cnt) {
            key = it.second->key;
            maxcnt = it.second->cnt;
        }
        preorder(it.second, maxcnt, key);
    }
}

int main()
{
	string arr[] ={"geeks", "for", "geeks", "a", 
 			"portal", "to", "learn", "can", "be", 
            "computer", "science", "zoom", "yup", 
            "fire", "in", "be", "data", "geeks"};
    int n = sizeof(arr)/sizeof(arr[0]);
    Trie *root = getNode();
    for(int i=0;i<n;i++)
    {
    	insert(root,arr[i]);
    }
    string key;
    int cnt = 0;
    preorder(root,cnt,key);
    cout<<key<<" "<<cnt;
}