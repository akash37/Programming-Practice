#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
pair<int,pair<int,int> >p[MAX];
int id[MAX];
void initialize()
{
	for(int i=0;i<MAX;i++){
		id[i] = i;
	}
}
int root(int x)
{
	while(x != id[x])
		x = id[x];
	return x;
}
void union1(int x,int y)
{
	int p = root(x);
	int q = root(y);
	id[p] = q;
}
int kruskal(int edges)
{
	int x,y,mincost=0,cost=0;
	for(int i=0;i<edges;i++)
	{
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if(root(x)!=root(y))
		{
			union1(x,y);
			mincost += cost;
		}
	}
	return mincost;
}
int main()
{
	int edges;
	cin>>edges;
	int x,y,w;
	initialize();
	for(int i=0;i<edges;i++)
	{
		cin>>x>>y>>w;
		p[i] = make_pair(w,make_pair(x,y));
	}
	sort(p,p+edges);
	/*for(int i=0;i<edges;i++)
	{
		cout<<p[i].first<<" "<<p[i].second.first<<"->"<<p[i].second.second<<endl;
	}*/
	int minc = kruskal(edges);
	cout<<"MST: "<<minc;
}