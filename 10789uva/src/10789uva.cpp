#include <bits/stdc++.h>

using namespace std;

bool prime[2001] ;

void sieve(){
	prime[0]=prime[1]=false ;
	for(int i=2 ; i*i<2001 ; i++){
		if(prime[i]){
			for(int j=i*i ; j<2001 ; j+=i){
				prime[j]=false ;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("angle2.in","r",stdin);
//	freopen("angle2.out","w",stdout);
	int t;
	memset(prime,true,sizeof(prime)) ;
	sieve() ;
	cin>>t ;
	string s ;
	for(int i=0 ; i<t ; i++){
		bool bl=false ;
		cin>>s ;
		cout<<"Case "<<i+1<<": ";
		sort(s.begin(), s.end()) ;
		int cnt=1 ;
		for(int j=1 ; j<s.size() ; j++){
			if(s[j]==s[j-1]) cnt++ ;
			else{
				if(prime[cnt]){
					cout<<s[j-1] ;
					bl=true ;
				}
				cnt=1 ;
			}
		}
		if(prime[cnt]){
			cout<<s[s.size()-1] ;
			bl=true ;
		}
		if(!bl) cout<<"empty" ;
		cout<<endl ;
	}

	return 0 ;
}
