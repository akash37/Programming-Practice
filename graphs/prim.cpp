#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
vector<pair<int,int> >v[MAX];
bool visited[MAX];
void prim(int so)
{
	for(int i=0;i<MAX;i++)
		visited[i] = false;
	priority_queue< pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > q;
	int x,y,we,mincost=0;
	q.push(make_pair(0,so));
	pair<int,int>p;
	while(!q.empty())
	{
		p = q.top();
		q.pop();
		x = p.second;
		we = p.first;
		if(visited[x])
			continue;
		mincost += we;
		visited[x] = true;
		for(int i=0;i<v[x].size();i++)
		{
			y = v[x][i].second;
			if(visited[y] == false)
			{
				q.push(v[x][i]);
			}
		}
	}
	cout<<"MST: "<<mincost;
}
int main()
{
	int n,e,a,b,w;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>w;
		v[a].push_back(make_pair(w,b));
		v[b].push_back(make_pair(w,a));
	}
	int so;
	cout<<"Enter Source"<<endl;
	cin>>so;
	prim(so);
}