#include <bits/stdc++.h>

using namespace std;

int num;

int num_devisors (int l, int r){
	int cnt=0,mx=0 ;
	for(int i=l ; i<=r ; i++){
		cnt=0 ;
		for(long long j=1 ; j*j<=i ; j++){
			if(!(i%j)){
				cnt++ ;
				if(j*j != i) cnt++ ;
			}
		}
		if(cnt>mx){
			mx=cnt ;
			num=i ;
		}
	}
	return mx ;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("angle2.in","r",stdin);
//	freopen("angle2.out","w",stdout);
	int n;
	cin>>n ;
	while(n--){
		int l,r ;
		cin>>l>>r ;
		int mx = num_devisors(l,r) ;
		cout<<"Between "<<l<<" and "<<r<<", "<<num<<" has a maximum of "<<mx<<" divisors."<<endl;
	}
	return 0 ;
}
