#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n ;
		int arr[n];
		for(int i=0 ; i<n ; i++) cin>>arr[i] ;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<i ; j++){
				if(arr[i]>=arr[j]) sum++ ;
			}
		}
		cout<<sum<<endl ;
	}
	return 0;
}
