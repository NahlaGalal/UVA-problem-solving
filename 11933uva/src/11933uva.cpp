#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n,cnt=0 ;
	while(cin>>n){
		cnt=0 ;
		int a=0,b=0 ;
		if(n==0) break ;
		for(int i=0 ; i<=31 ; i++){
			bool t=n&(1<<i) ;
			if(t){
				cnt++ ;
				if(cnt%2!=0) b|=(1<<i) ;
				else a|=(1<<i) ;
			}
		}
		cout<<b<<" "<<a<<endl ;
	}
	return 0;

}
