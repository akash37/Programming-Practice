#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int price[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>price[i];
	}
	int dp[n+1][n+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if(j<i)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],price[i]+dp[i][j-i]);
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<dp[n][n];
}