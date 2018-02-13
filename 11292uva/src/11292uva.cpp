#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n,m ;
	while(cin>>n>>m){
		if(n==0 && m==0) break ;
		int arr[n],arr2[m],sum=0 ;
		bool flag=false ;
		for(int i=0 ; i<n ; i++) cin>>arr[i] ;
		for(int i=0 ; i<m ; i++) cin>>arr2[i] ;
		sort(arr,arr+n) ;
		sort(arr2,arr2+m) ;
		int index=0 ;
		for(int i=0 ; i<m ; i++){
			if(arr2[i]>=arr[index]){
				index++ ;
				sum+=arr2[i] ;
			}
			if(index==n){
				flag=true ;
				break;
			}
		}
		if(flag) cout<<sum<<endl ;
		else cout<<"Loowater is doomed!"<<endl ;
	}
	return 0 ;
}
