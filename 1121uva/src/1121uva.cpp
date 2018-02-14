#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n,m ;
	while(cin>>n>>m){
		int arr[n],mn=n+1,sum=0,st=0;
		for(int i=0 ; i<n; i++) cin>>arr[i] ;
		sum=arr[0] ;
		for(int i=0 ; i<n ; i++){
			if(sum<m){
				while(sum<m){
					i++ ;
					if(i==n) break ;
					sum+=arr[i] ;
				}
			}
			if(sum>=m){
				mn=min(mn,i-st+1) ;
				sum-=arr[st] ;
				st++ ;
				i-- ;
			}
		}
		if(mn==n+1) cout<<0<<endl ;
		else cout<<mn<<endl ;
	}
	return 0 ;
}
