#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	priority_queue<int>pq;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		pq.push(a[i]);
	}
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
}