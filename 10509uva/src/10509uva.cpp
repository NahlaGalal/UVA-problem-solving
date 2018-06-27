#include <bits/stdc++.h>

using namespace std;

int cub[101] ;

void cubic(){
    for(int i=0 ; i<=100 ; i++) cub[i] = i*i*i ;
}

int binary_search(double x){
    int l=0 , r=101 ;
    while(l < r){
        int mid = l + (r - l + 1)/2 ;
        if(cub[mid] > x) r = mid - 1 ;
        else l = mid;
    }
    return l;
}

int main(){
    cubic() ;
    double n ;
    while(cin>>n && n){
        int a = binary_search(n) ;
        double dx = (n-double(cub[a]))/(3*double(a)*double(a));
        double res = double(a)+dx ;
        cout<<fixed<<setprecision(4)<<res<<endl ;
    }
    return 0;
}
