#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n;
	while(cin>>n){
		if(n==0) break;
		int arr[n][n] ;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++) cin>>arr[i][j] ;
		}
		bool bl1=false,flag=false,bl2=false ;
		int row,col,ones ;
		for(int i=0 ; i<n ; i++){
			ones=0 ;
			for(int j=0 ; j<n ; j++){
				if(arr[i][j]) ones++ ;
			}
			if(ones%2!=0){
				if(bl1){
					flag=true ;
					break ;
				}
				else{
					bl1=true ;
					row=i ;
				}
			}
		}
		for(int i=0 ; i<n ; i++){
			ones=0 ;
			for(int j=0 ; j<n ; j++){
				if(arr[j][i]) ones++ ;
			}
			if(ones%2!=0){
				if(bl2){
					flag=true ;
					break ;
				}
				else{
					bl2=true ;
					col=i ;
				}
			}
		}
		if(flag) cout<<"Corrupt" ;
		else{
			if(bl1 && bl2) cout<<"Change bit ("<<row+1<<","<<col+1<<")" ;
			else cout<<"OK" ;
		}
		cout<<endl ;
	}
	return 0;

}
