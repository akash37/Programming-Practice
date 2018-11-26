#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int mat[n][2];
	int a,b;
	int row = col = 0;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		mat[i][0] = a;
		mat[i][1] = b;
		row = max(row,b);
		col = col + a;
	}

}