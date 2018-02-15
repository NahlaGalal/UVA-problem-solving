#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n,q;
	vector<int> vec;
	int a ;
	cin>>n;
	for(int i=0 ; i<n; i++){
		int in;
		cin>>in ;
		vec.push_back(in) ;
	}
	cin>>q ;
	vector<int> :: iterator it;
	for(int i=0 ; i<q ; i++){
		cin>>a ;
		if(a==vec[0] && vec[0]==vec[n-1]){
			cout<<"X X"<<endl ;
			continue ;
		}
		if(a>vec[n-1]){
			cout<<vec[n-1]<<" X"<<endl ;
			continue ;
		}
		if(a<vec[0]){
			cout<<"X "<<vec[0]<<endl ;
			continue ;
		}
		if(a==vec[0]){
			it=upper_bound(vec.begin(),vec.end(),a);
			cout<<"X "<<*it<<endl ;
			continue ;
		}
		if(a==vec[n-1]){
			bool bl=false ;
			for(int j=n-1 ; j>=0 ; j--){
				if(vec[j]<a){
					cout<<vec[j]<<" X"<<endl ;
					bl=true ;
					break ;
				}
			}
			if(bl) continue ;
		}
		it=upper_bound(vec.begin(),vec.end(),a) ;
		for(int j=(it-vec.begin())-1 ; j>=0 ; j--){
			if(vec[j]!=a){
				cout<<vec[j]<<" "<<*it<<endl ;
				break ;
			}
		}
	}
	return 0 ;
}
