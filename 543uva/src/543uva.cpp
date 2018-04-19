#include <bits/stdc++.h>

using namespace std;

bool prime[10000001] ;

void Sieve(){
	prime[0]=false ;
	for(long long i=2 ; i*i<=10000000 ; i++){
		if(prime[i]){
			for(long long j=i*i ; j<=10000000 ; j+=i){
				prime[j]=false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("angle2.in","r",stdin);
//	freopen("angle2.out","w",stdout);
	int n ;
	memset(prime,true,sizeof(prime)) ;
	Sieve();
	while(cin>>n && n){
		int c=0 ;
		for(int i=3 ; i<=n/2 ; i++){
			if(prime[i] && prime[n-i]){
				c=i ;
				break ;
			}
		}
		if(!c) cout<<"Goldbach's conjecture is wrong."<<endl ;
		else cout<<n<<" = "<<c<<" + "<<n-c<<endl ;
	}
	return 0 ;
}
