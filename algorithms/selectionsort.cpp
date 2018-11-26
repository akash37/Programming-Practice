#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		int min = i;
		int j;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
				min = j;
		}
		//swap min and j
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}