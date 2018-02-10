#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n ;
	while(cin>>n){
		if(n==0) break;
		int arr[n],mx=0 ;
		for(int i=0 ; i<n ; i++){
			cin>>arr[i] ;
			mx=max(mx,arr[i]) ;
		}
		int freq[mx+1] ;
		memset(freq,0,sizeof(freq)) ;
		for(int i=0 ; i<n ; i++) freq[arr[i]]++ ;
		int cnt=0 ;
		for(int i=0 ; i<mx+1 ; i++){
			if(freq[i]){
				while(freq[i]--){
					arr[cnt]=i ;
					cnt++ ;
				}
			}
		}
		for(int i=0 ; i<n ; i++){
			cout<<arr[i] ;
			if(i!=n-1) cout<<" " ;
		}
		cout<<endl ;
	}
	return 0;
}
