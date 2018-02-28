#include <bits/stdc++.h>

using namespace std ;

vector<string> dirc;
int a,b,index,curx,cury ;
char arr[9][9] ;
string s="@IEHOVA#" ;

bool valid(int x, int y){
	if(x<0 || x==a) return false ;
	else if(y<0 || y==b) return false ;
	else return true ;
}

void path(int x,int y){
	if(!valid(x,y)) return ;
	if(arr[x][y]==s[7] && index==7){
		if(x+1==curx) dirc.push_back("forth") ;
		else if(y-1==cury) dirc.push_back("right") ;
		else if(y+1==cury) dirc.push_back("left") ;
		return ;
	}
	if(arr[x][y]==s[index]){
		index++ ;
		if(x+1==curx) dirc.push_back("forth") ;
		else if(y-1==cury) dirc.push_back("right") ;
		else if(y+1==cury) dirc.push_back("left") ;
		curx=x ;
		cury=y ;
		path(x-1,y) ;
		path(x,y-1) ;
		path(x,y+1) ;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n;
	cin>>n ;
	while(n--){
		dirc.clear() ;
		cin>>a>>b ;
		for(int i=0 ; i<a ; i++){
			for(int j=0 ; j<b ; j++){
				cin>>arr[i][j] ;
				if(arr[i][j]=='@'){
					curx=i ;
					cury=j ;
				}
			}
		}
		index=0 ;
		path(curx,cury) ;
		for(int i=0 ; i<dirc.size() ; i++){
			if(i) cout<<" "<<dirc[i] ;
			else cout<<dirc[i] ;
		}
		cout<<endl ;
	}
	return 0 ;
}
