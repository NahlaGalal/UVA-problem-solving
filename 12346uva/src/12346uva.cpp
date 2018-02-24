#include <bits/stdc++.h>

using namespace std ;

int n,arr[21][2],m;
long long arm,sum=0,s=0,mn=1000000001  ;

void mincost(int a){
		for(int i=a ; i<n ; i++){
			sum+=arr[i][0] ;
			s+=arr[i][1] ;
			if(arm<sum) mn=min(mn,s);
			mincost(i+1) ;
			sum-=arr[i][0] ;
			s-=arr[i][1] ;
		}
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	cin>>n ;
	long long a,b ;
	for(int i=0 ; i<n ; i++) cin>>arr[i][0]>>arr[i][1] ;
	cin>>m ;
	for(int i=0 ; i<m ; i++){
		cin>>a>>b ;
		arm=a/b ;
		sum=0;
		s=0 ;
		mn=1000000001;
		mincost(0) ;
		if(mn!=1000000001) cout<<"Case "<<i+1<<": "<<mn<<endl ;
		else cout<<"Case "<<i+1<<": IMPOSSIBLE"<<endl ;
	}
	return 0 ;
}
