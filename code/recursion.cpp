#include<bits/stdc++.h>
using namespace std;
int sum = 0;

int display(int num,int s)
{
	if(num>1)
	{
		s = s + num;
		display(num-1,s);
	}
	return s;
}

int main()
{
	int n;
	cin>>n;
	int s = display(n,0);
	cout<<s;
}