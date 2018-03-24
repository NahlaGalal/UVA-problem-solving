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
	int t;
	cin>>t ;
	while(t--){
		int n,m ;
		cin>>n>>m ;
		int a,b,c ;
		edjeList.clear() ;
		for(int i=0 ; i<m ; i++){
			cin>>a>>b>>c ;
			edjeList.push_back(make_pair(c, make_pair(a-1,b-1))) ;
		}
		sort(edjeList.begin(),edjeList.end()) ;
		int cost1=0 ;
		unionFind uf(n) ;
		vector<int> mst ;
		for(int i=0 ; i<m ; i++){
			int frontf=edjeList[i].second.first, fronts=edjeList[i].second.second ;
			if(!uf.isSameSet(frontf, fronts)){
				cost1+=edjeList[i].first ;
				mst.push_back(i) ;
				uf.unionSet(frontf, fronts) ;
			}
		}
		int temp,mn=1000000 ;
		for(int i=0 ; i<mst.size() ; i++){
			temp=edjeList[mst[i]].first ;
			edjeList[mst[i]].first=-1 ;
			unionFind u(n) ;
			int cost2=0 ;
			for(int j=0 ; j<m ; j++){
				if(edjeList[j].first==-1) continue ;
				int frontf=edjeList[j].second.first, fronts=edjeList[j].second.second ;
				if(!u.isSameSet(frontf, fronts)){
					cost2+=edjeList[j].first ;
					u.unionSet(frontf, fronts) ;
				}
			}
//			cout<<cost2<<endl ;
			if(cost2>=cost1) mn=min(mn,cost2) ;
			edjeList[mst[i]].first=temp ;
		}
		cout<<cost1<<" "<<mn<<endl ;
	}
	return 0 ;
}
