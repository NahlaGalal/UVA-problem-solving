#include <bits/stdc++.h>

using namespace std ;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n;
	cin>>n ;
	while(n--){
		int p,cnt=1000000,in=0,a=0 ;
		cin>>p ;
		vector<int> indx ;
		for(int i=0 ; i<p ; i++){
			a=0 ;
			cin>>in ;
			while(cin.get()!='\n'){
				cin>>in ;
				a++ ;
			}
//			cout<<in<<endl ;
			if(a<cnt){
				indx.clear() ;
				cnt=a ;
				indx.push_back(i) ;
			}
			else if(a==cnt) indx.push_back(i) ;
		}
		for(int i=0 ; i<indx.size() ; i++){
			if(i) cout<<" "<<indx[i]+1 ;
			else cout<<indx[i]+1 ;
		}
		cout<<endl ;
	}
	return 0 ;
}
