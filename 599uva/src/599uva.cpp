#include <bits/stdc++.h>

using namespace std;

vector<vector <int> > v(26) ;
vector <int> vec;
bool visited[26] ;
int c ;

void dfs(int node){
	visited[node]=true ;
	for(int i=0 ; i<v[node].size() ; i++){
		int child=v[node][i] ;
		if(!visited[child]) dfs(child) ;
	}
}

int connected_components(){
	int cnt=0 ;
	c=0 ;
	for(int i=0 ; i<vec.size() ; i++){
		if(!visited[vec[i]]){
//			cout<<vec[i]<<" "<<v[vec[i]].size()<<"\t" ;
//			for(int j=0 ; j<v[vec[i]].size() ; j++){
//				cout<<v[vec[i]][j]<<" " ;
//			}
//			cout<<endl ;
			if(v[vec[i]].size()>0){
				dfs(vec[i]) ;
				cnt++ ;
			}
			else c++ ;
		}
	}
	return cnt ;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int t ;
	cin>>t ;
	while(t--){
		string s ;
		memset(visited,false,sizeof(visited)) ;
		for(int i=0 ; i<26 ; i++) v[i].clear() ;
		vec.clear() ;
		while(cin>>s){
			if(s[0]=='('){
				int a=s[1]-'A' ;
				int b=s[3]-'A' ;
				v[a].push_back(b) ;
				v[b].push_back(a) ;
			}
			else if(isalpha(s[0])){
				for(int i=0 ; i<s.size() ; i+=2){
					int a=s[i]-'A' ;
					vec.push_back(a) ;
				}
				break ;
			}
		}
		int cnt=connected_components() ;
		cout<<"There are "<<cnt<<" tree(s) and "<<c<<" acorn(s)."<<endl ;
	}
	return 0 ;
}
