#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int t ;
	cin>>t ;
	for(int i=0 ; i<t ; i++){
		int n,p,q,sum=0,cnt=0 ;
		cin>>n>>p>>q ;
		int arr[n] ;
		for(int i=0 ; i<n ; i++) cin>>arr[i] ;
		sort(arr,arr+n) ;
		for(int i=0 ; i<n ; i++){
			sum+=arr[i] ;
			cnt++ ;
			if(sum>q || cnt>p){
				cnt-- ;
				break ;
			}
		}
		cout<<"Case "<<i+1<<": "<<cnt<<endl;
	}
	return 0 ;
}
