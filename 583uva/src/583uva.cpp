#include <bits/stdc++.h>

using namespace std;

vector <int> vec,primes;
bool prime[1000000] ;

void Seive(){
	prime[0]=prime[1]=false ;
	for(long long i=2 ; i*i<=1000000 ; i++){
		if(prime[i]){
			for(long long j=i*i ; j<=1000000 ; j+=i) if(prime[j]) prime[j]=false ;
		}
	}
	for(int i=0 ; i<=1000000 ; i++){
		if(prime[i]) primes.push_back(i) ;
	}
}

void factors(int n){
	int a=0,m ;
	m=n ;
	while(primes[a]*primes[a]<=m && n>1){
		while(!(n%primes[a])){
			vec.push_back(primes[a]) ;
			n/=primes[a] ;
		}
		a++ ;
		if(a==primes.size()) break ;
	}
	if(n!=1) vec.push_back(n) ;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("angle2.in","r",stdin);
//	freopen("angle2.out","w",stdout);
	int n;
	memset(prime, true, sizeof(prime));
	Seive() ;
	while(cin>>n && n){
		cout<<n<<" = " ;
		if(n<0){
			cout<<"-1 x ";
			n*=-1 ;
		}
		vec.clear();
		factors(n);
		for(int i=0 ; i<vec.size() ; i++){
			if(i!=vec.size()-1) cout<<vec[i]<<" x " ;
			else cout<<vec[i] ;
		}
		cout<<endl ;
	}
	return 0 ;
}
