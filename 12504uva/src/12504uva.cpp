#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n;
	cin>>n ;
	for(int i=0 ; i<n ; i++){
		map<string,string> mp,mp2 ;
		map<string,string> :: iterator it;
		vector<string> plus,minus,multiple ;
		string s,c="",num="" ;
		cin>>s ;
		if(s.size()>2){
			for(int i=1 ; i<s.size() ; i++){
				if(isalpha(s[i])) c+=s[i] ;
				else if (s[i]==',' || s[i]=='}'){
					mp[c]=num ;
					c="" ;
					num="" ;
				}
				else num+=s[i] ;
			}
		}
		cin>>s ;
		if(s.size()>2){
			for(int i=1 ; i<s.size() ; i++){
				if(isalpha(s[i])) c+=s[i] ;
				else if (s[i]==',' || s[i]=='}'){
					mp2[c]=num ;
					c="" ;
					num="" ;
				}
				else num+=s[i] ;
			}
		}
		for(it=mp.begin() ; it!=mp.end() ; it++){
			if(mp2.find(it->first)==mp2.end()) minus.push_back(it->first) ;
			else if((it->second)!=mp2[(it->first)]) multiple.push_back(it->first) ;
		}
		for(it=mp2.begin() ; it!=mp2.end() ; it++){
			if(mp.find(it->first)==mp.end()) plus.push_back(it->first) ;
		}
		if(minus.size()==0 && plus.size()==0 && multiple.size()==0) cout<<"No changes"<<endl ;
		for(int i=0 ; i<plus.size() ; i++){
			if(i==0) cout<<'+' ;
			cout<<plus[i] ;
			if(i!=plus.size()-1) cout<<',' ;
			else cout<<endl ;
		}
		for(int i=0 ; i<minus.size() ; i++){
			if(i==0) cout<<'-' ;
			cout<<minus[i] ;
			if(i!=minus.size()-1) cout<<',' ;
			else cout<<endl ;
		}
		for(int i=0 ; i<multiple.size() ; i++){
			if(i==0) cout<<'*' ;
			cout<<multiple[i] ;
			if(i!=multiple.size()-1) cout<<',' ;
			else cout<<endl ;
		}
		cout<<endl ;
	}
	return 0;
}
