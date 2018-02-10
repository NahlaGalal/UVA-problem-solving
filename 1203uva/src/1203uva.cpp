#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	string s ;
	int k,in1,in2 ;
	vector<pair <int,unsigned long long> > vec;
	map<int,int> mp ;
	while(cin>>s){
		if(s=="#") break ;
		cin>>in1>>in2 ;
		vec.push_back(make_pair(in2,in1)) ;
		mp[in1]=in2;
	}
	cin>>k ;
	while(k--){
		sort(vec.begin(),vec.end()) ;
		cout<<vec[0].second<<endl ;
		vec[0].first+= mp[vec[0].second];
	}
	return 0;
}
