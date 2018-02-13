#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n,in;
	while(cin>>n){
		if(n==0) break ;
		multiset<int> st ;
		for(int i=0 ; i<n ; i++){
			cin>>in ;
			st.insert(in) ;
		}
		int a,sum=0 ;
		while(st.size()>1){
			a=*st.begin() ;
			st.erase(st.begin()) ;
			a+=*st.begin() ;
			st.erase(st.begin()) ;
			st.insert(a) ;
			sum+=a ;
		}
		cout<<sum<<endl ;
	}
	return 0 ;
}
