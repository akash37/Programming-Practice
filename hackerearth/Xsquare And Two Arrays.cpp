#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;
	cin>>n>>q;
	long long int a[n+1],b[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	long long int sum1[n+1],sum2[n+1];
	sum1[1] = a[1];
	sum2[1] = b[1];
	sum1[0] = 0;
	sum2[0] = 0;
	for(int i=2;i<=n;i++)
	{
		if(i%2==0)
		{
			sum1[i] = sum1[i-1] + b[i];
			sum2[i] = sum2[i-1] + a[i];
		}
		else
		{
			sum1[i] = sum1[i-1] + a[i];
			sum2[i] = sum2[i-1] + b[i];
		}
	}
	
	for(int i=1;i<=n;i++)
	{
	    cout<<sum1[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
	    cout<<sum2[i]<<" ";
	}
	while(q--)
	{
		int type,l,r;
		cin>>type>>l>>r;
		if(type == 1)
		{
			cout<<sum1[r] - sum1[l-1]<<endl;
		}
		else
		{
			cout<<sum2[r] - sum2[l-1]<<endl;
		}
	}
}
