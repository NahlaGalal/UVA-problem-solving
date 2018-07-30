#include <bits/stdc++.h>

using namespace std;

// Char in Integer ==> A=17, a=49
bool cmp(const pair<int, int> &a, const pair <int, int> &b){ //Rearrange pair by second
	return (a.second < b.second);
}

int main(){
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int z,i,m,l,cnt=1 ;
	while(cin>>z>>i>>m>>l){
		if(!z && !i && !m && !l) break;
		set<int> st;
		int sz = -1;
		while(st.size() != sz){
			sz = st.size();
			int res = (z * l + i)%m ;
			st.insert(res) ;
			l = res;
		}
		cout<<"Case "<<cnt<<": "<<st.size()<<endl ;
		cnt++ ;
	}
	return 0;

}
