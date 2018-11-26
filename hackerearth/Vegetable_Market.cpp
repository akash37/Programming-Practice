#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int totalsum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		totalsum += a[i];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int k;
		cin>>k;
		int m = ceil(n/k);
		int sum = 0;
		if(k>totalsum)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			while(1)
			{
				for(int i=0;i<n;i++)
				{
					if(a[i]<m){
						sum+=a[i];
					}
					else{
						sum+=m;
					}
				}
				if(sum>=k){
					cout<<m<<endl;
					break;
				}
				else{
					sum = 0;
					m++;
				}
			}
		}
	}
}