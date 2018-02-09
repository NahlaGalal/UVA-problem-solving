#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	string s ;
	set <string> st ;
	while(cin>>s){
		string c="";
		for(int i=0 ; i<s.size() ; i++){
			if(isalpha(s[i])) c+=tolower(s[i]) ;
			else{
				if(c!="") st.insert(c) ;
				c="" ;
			}
		}
		if(c!="") st.insert(c) ;
	}
	while(st.size()!=0){
		cout<<*(st.begin())<<endl ;
		st.erase(st.begin()) ;
	}
	return 0;
}
