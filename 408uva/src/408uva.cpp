#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("angle2.in","r",stdin);
//	freopen("angle2.out","w",stdout);
	int step,mod,seed,sz ;
	while(cin>>step>>mod){
		seed = 0;
		bool flag=false;
		set<int> st;
		st.insert(0);
		sz=1 ;
		for(int i=0 ; i<mod-1 ; i++){
			seed = (seed%mod+step%mod)%mod ;
			st.insert(seed);
			if(st.size() == sz){
				flag = true;
				break ;
			}
			sz = st.size();
		}
		if(flag) cout<<setw(10)<<step<<setw(10)<<mod<<"    Bad Choice"<<endl;
		else cout<<setw(10)<<step<<setw(10)<<mod<<"    Good Choice"<<endl ;
		cout<<endl ;
	}
	return 0 ;
}
