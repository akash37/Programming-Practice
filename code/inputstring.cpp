#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s = "12 50 60 70 600 1";
	vector<int>v;
	string s1="";
	for(int i=0;i<s.length();i++)
	{
		if(s[i] == ' '){
			int x = 0;
			stringstream geek(s1);
			geek>>x; 
			v.push_back(x);
			s1 = "";
		}
		else{
			s1 = s1 + s[i];
		}
	}
	int x = 0;
	stringstream geek(s1);
	geek>>x; 
	v.push_back(x);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}