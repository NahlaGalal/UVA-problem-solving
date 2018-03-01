#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n,m,inp ;
	while(cin>>n>>m){
		vector <vector <int> > vec(1000001) ;
		for(int i=0 ; i<n ; i++){
			cin>>inp ;
			vec[inp].push_back(i+1) ;
		}
		int a,b ;
		for(int i=0 ; i<m ; i++){
			cin>>a>>b ;
			if(a<=vec[b].size()) cout<<vec[b][a-1]<<endl ;
			else cout<<0<<endl ;
		}
	}
	return 0 ;
}
