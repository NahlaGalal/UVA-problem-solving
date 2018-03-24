#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int,int> > > edjeList;

class unionFind{
private: vector<int> p,rank;
public:
	unionFind(int n){
		p.assign(n,0) ;
		rank.assign(n,0) ;
		for(int i=0 ; i<n ; i++) p[i]=i ;
	}

	int findSet(int i){
		return (p[i]==i) ? i : (p[i]=findSet(p[i])) ;
	}

	bool isSameSet(int i, int j){
		return findSet(i)==findSet(j) ;
	}

	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			int x=findSet(i), y=findSet(j);
			if(rank[x]>rank[y]) p[y]=x ;
			else{
				p[x]=y ;
				if(rank[x]==rank[y]) rank[y]++ ;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int n,m ;
	while(cin>>n>>m){
		if(n==0 && m==0) break ;
		edjeList.clear();
		int a,b,c ;
		for(int i=0 ; i<m ; i++){
			cin>>a>>b>>c ;
			edjeList.push_back(make_pair(c, make_pair(a,b))) ;
		}
		vector<int> heavy;
		sort(edjeList.begin(), edjeList.end()) ;
		unionFind uf(n) ;
		for(int i=0 ; i<m ; i++){
			if(!uf.isSameSet(edjeList[i].second.first, edjeList[i].second.second)){
				uf.unionSet(edjeList[i].second.first, edjeList[i].second.second) ;
			}
			else{
				heavy.push_back(edjeList[i].first) ;
			}
		}
		sort(heavy.begin(), heavy.end()) ;
		if(!heavy.size()) cout<<"forest" ;
		else for(int i=0 ; i<heavy.size() ; i++) cout<<heavy[i]<<" " ;
		cout<<endl ;
	}
	return 0 ;
}
