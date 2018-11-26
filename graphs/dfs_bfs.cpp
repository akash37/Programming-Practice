#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int visited[11];
vector<int>v[11];
void dfs(int so)
{
	visited[so] = 1;
	cout<<so<<" ";
	for(int i=0;i<v[so].size();i++)
	{
		if(visited[v[so][i]] == 0)
			dfs(v[so][i]);
	}
}

void DFS(int so)
{
	stack<int>s;
	s.push(so);
	while(!s.empty())
	{
		int temp = s.top();
		visited[temp] = 1;
		cout<<temp<<" ";
		s.pop();
		for(int i=0;i<v[temp].size();i++)
		{
			if(visited[v[temp][i]] == 0)
			{
				s.push(v[temp][i]);
				visited[v[temp][i]] = 1;
			}
		}
	}
}

void BFS(int so)
{
	queue<int>q;
	q.push(so);
	while(!q.empty())
	{
		int temp = q.front();
		cout<<temp<<" ";
		q.pop();
		visited[temp] = 1;
		for(int i=0;i<v[temp].size();i++)
		{
			if(visited[v[temp][i]] == 0)
			{
				q.push(v[temp][i]);
				visited[v[temp][i]] = 1;
			}
		}
	}
}

int main()
{
	int n,e;
	cout<<"Enter the number of Nodes and Edges"<<endl;
	cin>>n>>e;
	int a,b;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(visited,0,sizeof(visited));
	dfs(1);
	cout<<endl;
	memset(visited,0,sizeof(visited));
	DFS(1);
	memset(visited,0,sizeof(visited));
	cout<<endl;
	BFS(1);
	/*for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}*/
}