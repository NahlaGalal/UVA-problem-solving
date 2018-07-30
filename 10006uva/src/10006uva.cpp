#include <bits/stdc++.h>

using namespace std;

// Char in Integer ==> A=17, a=49
bool cmp(const pair<int, int> &a, const pair <int, int> &b){ //Rearrange pair by second
	return (a.second < b.second);
}

int mod;
bool isPrime[100000];

void Sieve(){
	isPrime[0] = isPrime[1] = false;
	for(long long i=2 ; i<100000 ; i++){
		if(isPrime[i]){
			for(long long j=i*2 ; j<100000 ; j+=i) isPrime[j] = false;
		}
	}
}

long long power(long long b, long long p){
	if(p == 0) return 1;
	if(p%2 == 0) return power((b*b)%mod, p/2);
	else return power(b, p-1)*b%mod ;
}

int main(){
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	memset(isPrime, true, sizeof(isPrime));
	Sieve();
	while(cin>>mod && mod){
		if(isPrime[mod]){
			cout<<mod<<" is normal."<<endl;
			continue;
		}
		bool flag = false;
		for(int i=2 ; i<mod ; i++){
			if(power(i, mod) == i) continue;
			else{
				flag = true;
				break;
			}
		}
		if(!flag) cout<<"The number "<<mod<<" is a Carmichael number."<<endl;
		else cout<<mod<<" is normal."<<endl;
	}
	return 0;

}
