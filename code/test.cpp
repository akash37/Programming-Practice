#include<bits/stdc++.h>
using namespace std;
int myCompare(int x,int y)
{
	string X = to_string(x);
    string Y = to_string(y);
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX)>0 ? 1 : 0;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,myCompare);
	string ans = "";
	for(int i=n;i>=0;i--)
	{
		s = s + to_string(a[i]); 
	}
	cout<<ans<<" ";
}