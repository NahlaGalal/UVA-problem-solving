#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n;
	while(cin>>n){
		if(n==0) break ;
		int m,s,sum=0 ;
		multiset<int> st ;
		set<int> :: iterator it ;
		for(int i=0 ; i<n ; i++){
			cin>>m ;
			st.insert(m) ;
		}
		while(st.size()>1){
			it=st.begin() ;
			s=*it ;
			st.erase(it) ;
			it=st.begin() ;
			s+=*it ;
			st.erase(it) ;
			st.insert(s) ;
			sum+=s ;
		}
		cout<<sum<<endl ;
	}

	return 0;
}
