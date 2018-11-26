#include<bits/stdc++.h>
#define pii pair<int,int>
#define MAX 1000
using namespace std;
vector<pii>v[MAX];
int dist[MAX];
bool visited[MAX];
int djikstra(int so,int d)
{
	for(int i=0;i<MAX;i++)
	{
		dist[i] = 100000;
		visited[i] = false;
	}
	dist[so] = 0;
	multiset<pii>s;
	s.insert(make_pair(0,so));
	while(!s.empty())
	{
		pii p = *s.begin();
		s.erase(s.begin());
		int x = p.second;
		int y = p.first;
		if(visited[x])
			continue;
		visited[x] = true;
		for(int i=0;i<v[x].size();i++)
		{
			int e = v[x][i].second;
			int we = v[x][i].first;
			if(dist[x]+we<dist[e])
			{
				dist[e] = dist[x] + we;
				s.insert(make_pair(dist[e],e));
			}
		}
	}
	return dist[d];
}
int main()
{
	int n,e,w,a,b;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>w;
		v[a].push_back(make_pair(w,b));
		v[b].push_back(make_pair(w,a));
	}
	cout<<"Enter the source and destination"<<endl;
	int so,d;
	cin>>so>>d;
	int cost = djikstra(so,d);
	cout<<cost<<endl;
}