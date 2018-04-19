#include <bits/stdc++.h>

using namespace std;

bool prime[1000001] ;
vector<int> vec ;

void Sieve(){
	prime[0]=prime[1]=false ;
	for(long long i=2 ; i*i<=1000000 ; i++){
		if(prime[i]){
			for(long long j=i*i ; j<=1000000 ; j+=i){
				prime[j]=false;
			}
		}
	}
	for(int i=2 ; i<=1000000 ; i++){
		if(prime[i]){
			int n=i,sum=0 ;
			while(n){
				sum+=n%10 ;
				n/=10 ;
			}
			if(prime[sum]) vec[i] = vec[i-1]+1 ;
			else vec[i] = vec[i-1] ;
		}
		else vec[i] = vec[i-1] ;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("angle2.in","r",stdin);
//	freopen("angle2.out","w",stdout);
	int n ;
	memset(prime,true,sizeof(prime)) ;
	vec.assign(1000001,0) ;
	Sieve();
	cin>>n ;
	while(n--){
		int a,b ;
		cin>>a>>b ;
		cout<<vec[b]-vec[a-1]<<endl ;
	}
	return 0 ;
}
