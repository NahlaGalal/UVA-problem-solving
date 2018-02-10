#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n,m,in ;
	long long salary=0 ;
	cin>>n>>m ;
	map<string,int> mp;
	string s ;
	for(int i=0 ; i<n ; i++){
		cin>>s>>in ;
		mp[s]=in ;
	}
	for(int i=0 ; i<m ; i++){
		while(cin>>s){
			if(s==".") break ;
			if(mp.find(s)!=mp.end()) salary+=mp[s] ;
		}
		cout<<salary<<endl ;
		salary=0 ;
	}
	return 0;
}
