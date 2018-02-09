#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n;
	cin>>n ;
	string s[n],c ;
	for(int i=0 ; i<n ; i++) cin>>s[i] ;
	for(int i=0 ; i<n ; i++){
		c=s[i] ;
		stack<char> st;
		for(int j=0 ; j<c.size() ; j++){
			if(isalpha(c[j])) cout<<c[j] ;
			else{
				if(c[j]==')'){
					cout<<st.top() ;
					st.pop() ;
				}
				else if(c[j]!='(') st.push(c[j]) ;
			}
		}
		while(st.size()!=0){
			cout<<st.top() ;
			st.pop() ;
		}
		cout<<endl ;
	}
	return 0;
}
