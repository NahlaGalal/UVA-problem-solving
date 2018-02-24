#include <bits/stdc++.h>

using namespace std ;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n,a=0 ;
	while(cin>>n && n){
		if(a) cout<<endl ;
		a=1 ;
		bool bl=false ;
		for(int i=1234 ; i<=98765/n ; i++){
			int a=i*n,tmp,used=(i<10000) ;
			tmp=i ;
			while(tmp>0){
				used|=(1<<tmp%10) ;
				tmp/=10 ;
			}
			tmp=a ;
			while(tmp>0){
				used|=(1<<tmp%10) ;
				tmp/=10 ;
			}
			if(used==(1<<10)-1){
				bl=true ;
				if(i>10000) cout<<a<<" / "<<i<<" = "<<n<<endl ;
				else cout<<a<<" / 0"<<i<<" = "<<n<<endl ;
			}
		}
		if(!bl) cout<<"There are no solutions for "<<n<<"."<<endl;
	}
	return 0 ;
}
