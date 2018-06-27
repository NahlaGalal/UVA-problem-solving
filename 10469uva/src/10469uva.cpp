#include <bits/stdc++.h>

using namespace std;

int main(){
    int x,y ;
    while(cin>>x>>y){
        bitset<32> b1(x), b2(y);
        int s = 0;
        for(int i=0 ; i<32 ; i++){
            if(b1.test(i) ^ b2.test(i)) s|=(1<<i) ;
        }
        cout<<s<<endl ;
    }
    return 0;
}
