#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n,m ;
	while(cin>>n>>m){
		if(n==0 && m==0) break ;
		int in,cnt=0 ;
		map<int,int> mp ;
		map<int,int> :: iterator it;
		for(int i=0 ; i<n ; i++){
			cin>>in ;
			mp[in]++ ;
		}
		for(int i=0 ; i<m ; i++){
			cin>>in ;
			mp[in]++ ;
		}
		for(it=mp.begin() ; it!=mp.end() ; it++){
			if((it->second)>1) cnt++ ;
		}
		cout<<cnt<<endl ;
	}
	return 0;
}
