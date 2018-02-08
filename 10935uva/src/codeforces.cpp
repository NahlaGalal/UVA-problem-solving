#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n,k;
	while(cin>>n){
		if(n==0) break ;
		deque <int> q;
		for(int i=1 ; i<=n ; i++) q.push_back(i) ;
		vector<int> vec;
		while(q.size()>1){
			vec.push_back(q.front()) ;
			q.pop_front() ;
			k=q.front() ;
			q.pop_front() ;
			q.push_back(k) ;
		}
		cout<<"Discarded cards: " ;
		for(int i=0 ; i<n-1 ; i++){
			cout<<vec[i] ;
			if(i!=n-2) cout<<", " ;
		}
		cout<<"\nRemaining card: "<<q.front()<<endl ;
	}
	return 0;

}
