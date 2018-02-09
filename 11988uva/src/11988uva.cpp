#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	string s,c="";
	while(cin>>s){
		c="" ;
		deque<string> q;
		for(int i=0 ; i<s.size() ; i++){
			if(s[i]!='[' && s[i]!=']') c+=s[i] ;
			else if(s[i]==']') continue ;
			else{
				q.push_back(c) ;
				c="" ;
				i++ ;
				while(s[i]!=']' && i!=s.size()){
					if(s[i]=='['){
						q.push_front(c) ;
						c="" ;
						i++ ;
					}
					else{
						c+=s[i] ;
						i++ ;
					}
				}
				q.push_front(c) ;
				c="" ;
			}
		}
		q.push_back(c) ;
		while(q.size()>0){
			cout<<q.front() ;
			q.pop_front() ;
		}
		cout<<endl ;
	}
	return 0;
}
