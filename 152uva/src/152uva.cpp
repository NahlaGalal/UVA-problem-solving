#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("angle2.in","r",stdin);
//	freopen("angle2.out","w",stdout);
	int x,y,z ;
	int arr[10],index=0,d[5001][3] ;
	memset(arr,0,sizeof(arr)) ;
	while(cin>>x>>y>>z){
		if(!x && !y && !z) break ;
		d[index][0]=x ;
		d[index][1]=y ;
		d[index][2]=z ;
		index++ ;
	}
	for(int i=0 ; i<index ; i++){
		int mn=1000 ;
		for(int j=0 ; j<index ; j++){
			if(i==j) continue ;
			int dist=sqrt((d[i][0]-d[j][0])*(d[i][0]-d[j][0]) + (d[i][1]-d[j][1])*(d[i][1]-d[j][1]) + (d[i][2]-d[j][2])*(d[i][2]-d[j][2])) ;
			if(dist>=10) continue ;
			mn=min(mn, dist) ;
		}
		if(mn>=10) continue ;
		arr[mn]++ ;
	}
	for(int i=0 ; i<10 ; i++) cout<<setw(4)<<arr[i] ;
	cout<<endl ;
	return 0 ;
}
