#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arrival[n];
	    int departure[n];
	    for(int i=0;i<n;i++){
	        cin>>arrival[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>departure[i];
	    }
	    vector< pair<int,int> >v;
	    for(int i=0;i<n;i++)
	    {
	        v.push_back(make_pair(arrival[i],1));
	        v.push_back(make_pair(departure[i],-1));
	    }
		sort(v.begin(),v.end());
	    int cumm[v.size()];
	    int ans[v.size()];
	    for(int i=0;i<v.size();i++){
	    	ans[i] = v[i].second;
	    }
	    cumm[0] = ans[0];
	    for(int i=1;i<v.size();i++)
	    {
	        cumm[i] = cumm[i-1] + v[i].second;
	    }
	    int max = INT_MIN;
	    for(int i=0;i<v.size();i++){
	    	cout<<cumm[i]<<" ";
	        if(cumm[i]>max){
	            max = cumm[i];
	        }
	    }
	    cout<<max<<endl;
	}
}