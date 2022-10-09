#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int w, x, y, z;
        cin>>w>>x>>y>>z;

        int total_water = w+y*z;
        if(total_water > x){
            cout<<"overflow\n";
        } else if(total_water == x){
            cout<<"filled\n";
        } else {
            cout<<"unfilled\n";
        }
    }
    return 0;
}