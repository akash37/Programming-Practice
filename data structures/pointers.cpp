#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cout<<"N = "<<n<<endl;
	cout<<"location of n"<<&n<<endl;
	int *ptr;
	cout<<"ptr"<<ptr<<endl;
	cout<<"location of ptr"<<&ptr<<endl;
	ptr = &n;
	cout<<"ptr"<<ptr<<endl;
	cout<<*ptr;
	int x;
	cout<<x;
}