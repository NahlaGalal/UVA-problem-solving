#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n;
	while(cin>>n){
		int x,y ;
		bool s=false,q=false,p=false ;
		stack<int> st;
		queue<int> qu;
		priority_queue <int> pq;
		for(int i=0 ; i<n; i++){
			cin>>x>>y ;
			if(x==1){
				st.push(y) ;
				qu.push(y) ;
				pq.push(y) ;
			}
			else{
				if(st.size()==0){
					s=true ;
					p=true;
					q=true ;
				}
				if(!s){
					if(y!=st.top()) s=true ;
					else st.pop() ;
				}
				if(!q){
					if(y!=qu.front()) q=true ;
					else qu.pop() ;
				}
				if(!p){
					if(y!=pq.top()) p=true ;
					else pq.pop() ;
				}
			}
		}
		if(!s && q && p) cout<<"stack"<<endl ;
		else if(!q && s && p) cout<<"queue"<<endl ;
		else if(!p && s && q) cout<<"priority queue"<<endl ;
		else if(s && p && q) cout<<"impossible"<<endl ;
		else cout<<"not sure"<<endl ;
	}
	return 0;
}
