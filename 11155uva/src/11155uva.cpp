#include <bits/stdc++.h>

using namespace std;

// Char in Integer ==> A=17, a=49
bool cmp(const pair<int, int> &a, const pair <int, int> &b){ //Rearrange pair by second
	return (a.second < b.second);
}

int subArray (int arr[], int m, int n){
	map<int, int> mp;
	map<int, int> :: iterator it;
	long long res = 0;
	for(int i=0 ; i<n ; i++) mp[(arr[i]%m)]++ ;
	for(it=mp.begin() ; it!=mp.end() ; it++){
		int cnt = it->second;
		res += cnt*(cnt-1)/2;
	}
	res+=mp[0] ;
	return res;
}

int main(){
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	int t, cnt=1;
	cin>>t ;
	while(t--){
		int a, b, c, m, n;
		cin>>a>>b>>c>>m>>n ;
		int arr[n], cum[n] ;
		arr[0] = cum[0] = a;
		for(int i=1 ; i<n; i++){
			arr[i] = ((arr[i-1]*b+c)%m)+1;
			cum[i] = arr[i] + cum[i-1];
		}
		cout<<"Case "<<cnt<<": "<<subArray(cum, m, n)<<endl;
		cnt++ ;
	}
	return 0;

}
