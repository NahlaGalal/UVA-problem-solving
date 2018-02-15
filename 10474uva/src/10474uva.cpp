#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n,q,cnt=0 ;
	while(cin>>n>>q){
		if(n==0 && q==0) break ;
		int a;
		cnt++ ;
		cout<<"CASE# "<<cnt<<":\n" ;
		vector<int> vec;
		for(int i=0 ; i<n ; i++){
			cin>>a ;
			vec.push_back(a) ;
		}
		sort(vec.begin(),vec.end()) ;
		vector<int> :: iterator it;
		for(int i=0 ; i<q ; i++){
			cin>>a ;
			it=lower_bound(vec.begin(),vec.end(),a) ;
			if(*it==a) cout<<*it<<" found at "<<(it-vec.begin())+1<<endl ;
			else cout<<a<<" not found"<<endl ;
		}
	}
	return 0 ;
}
