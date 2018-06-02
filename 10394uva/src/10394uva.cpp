#include <bits/stdc++.h>

using namespace std;

vector <int> prime;
bool p[20000002];

void sieve(){
	p[0]=p[1]=false ;
	for(long long i=2 ; i<20000001 ; i++){
		if(p[i]){
			for(long long j=i*i ; j<20000001 ; j+=i) p[j]=false ;
		}
	}
	for(int i=3 ; i<20000002 ; i++) if(p[i] && p[i-2]) prime.push_back(i);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("angle2.in","r",stdin);
//	freopen("angle2.out","w",stdout);
	memset(p,true,sizeof(p));
	sieve() ;
	int a ;
	while(cin>>a){
		cout<<"("<<prime[a-1]-2<<", "<<prime[a-1]<<")"<<endl ;
	}
	return 0 ;
}
