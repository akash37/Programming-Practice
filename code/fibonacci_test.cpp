#include<bits/stdc++.h>
using namespace std;
// int a = 0,b = 1,n;
// void fib(int a,int b,int num)
// {
// 	if(num == n)
// 		return;
// 	cout<<a+b<<" ";
// 	int temp;
// 	temp = a;
// 	a = b;
// 	b = temp+b;
// 	num++;
// 	fib(a,b,num);
// }
int fib(int n)
{
	if(n<2)
		return 1;
	else
		return fib(n-1) + fib(n-2);
}
int main()
{
	int n;
	cin>>n;
	int ans = fib(n);
	cout<<ans;
}