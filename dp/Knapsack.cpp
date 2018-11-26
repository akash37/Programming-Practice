#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,W;
	    cin>>n;
	    cin>>W;
	    int wt[n],val[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>val[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>wt[i];
	    }
	    int dp[n+1][W+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=W;j++)
	        {
	            if(i==0 || j==0)
	            {
	                dp[i][j] = 0;
	            }
	            else if(wt[i-1]>j)
	            {
	                dp[i][j] = dp[i-1][j];
	            }
	            else
	            {
	                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
	            }
	        }
	    }
	    cout<<dp[n][W]<<endl;
	}
}