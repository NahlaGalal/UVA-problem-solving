#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, arr[101], cnt=1;
    cin>>t ;
    arr[0] = 0;
    arr[1] = 1;
    for(int i=3 ; i<=100 ; i+=2) arr[i] = arr[i-2]+i ;
    for(int i=2 ; i<=100 ; i+=2) arr[i] = arr[i-1] ;
    while(t--){
        int a,b ;
        cin>>a>>b ;
        if(a==0) a=1 ;
        cout<<"Case "<<cnt<<": "<<arr[b]-arr[a-1]<<endl ;
        cnt++ ;
    }
    return 0;
}
