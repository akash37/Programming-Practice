#include<bits/stdc++.h>
using namespace std;
int max(int a,int b){
	return (a>b)?a:b;
}
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int val[n+1];
	val[0] = 0;
	for(int i=1;i<=n;i++)
	{
		int max_val = INT_MIN;
		for(int j=1;j<=i;j++)
		{
			max_val = max(max_val,a[j]+val[i-j]);
		}
		val[i] = max_val;
	}
	cout<<val[n];
}