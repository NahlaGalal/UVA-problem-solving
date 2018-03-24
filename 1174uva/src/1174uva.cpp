#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int,int> > > edgeList ;

class unionFind{
private: vector<int> p,rank;
public:
	unionFind(int n){
		rank.assign(n, 0);
		p.assign(n, 0);
		for(int i=0 ; i<n ; i++) p[i]=i ;
	}

	int findSet (int i){
		return (p[i]==i) ? i : (p[i]=findSet(p[i])) ;
	}

	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j) ;
	}

	void unionSet(int i, int j){
		if(!isSameSet(i,j)){
			int x=findSet(i), y=findSet(j);
			if(rank[x]>rank[y]) p[y]=x;
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
	int t ;
	cin>>t ;
	while(t--){
		edgeList.clear();
		int n,m ;
		cin>>n>>m ;
		int a,cnt=1 ;
		string s,c ;
		map<string,int> mp ;
		for(int i=0 ; i<m ; i++){
			cin>>s>>c>>a ;
			if(!mp[s]){
				mp[s]=cnt ;
				cnt++;
			}
			if(!mp[c]){
				mp[c]=cnt ;
				cnt++ ;
			}
			edgeList.push_back(make_pair(a, pair<int,int> ((mp[s]-1), (mp[c]-1)))) ;
		}
		sort(edgeList.begin(), edgeList.end()) ;
		int cost=0;
		unionFind uf(n);
		for(int i=0 ; i<m ; i++){
			pair<int, pair<int,int> > front= edgeList[i] ;
//			cout<<front.second.first<<" "<<front.second.second<<" "<<front.first<<endl ;
			if(!uf.isSameSet(front.second.first, front.second.second)){
				cost+=front.first ;
				uf.unionSet(front.second.first, front.second.second) ;
			}
		}
		cout<<cost<<endl ;
		if(t) cout<<endl ;
	}
	return 0 ;
}
