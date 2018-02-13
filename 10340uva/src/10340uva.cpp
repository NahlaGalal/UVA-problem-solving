#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	string s,t ;
	while(cin>>t>>s){
		int indx=0;
		for(int i=0 ; i<s.size() ; i++){
			if(s[i]==t[indx]) indx++ ;
			if(indx==t.size()) break ;
		}
		if(indx==t.size()) cout<<"Yes"<<endl ;
		else cout<<"No"<<endl ;
	}
	return 0 ;
}
