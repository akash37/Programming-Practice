#include<bits/stdc++.h>
using namespace std;
int a = 0,b = 1,n;
void fib(int a,int b,int num)
{
	if(num == n)
		return;
	cout<<a+b<<" ";
	int temp;
	temp = a;
	a = b;
	b = temp+b;
	num++;
	fib(a,b,num);
}
int main()
{
	cin>>n;
	cout<<a<<" "<<b<<" ";
	fib(a,b,1);
}