#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        if(n%2!=0){
            cout<<n/2<<endl;
        } else {
            long long int counter = 2;
            long long int k = n;
            while(n%2==0){
                n/=2;
                counter *= 2;
            }
            
            cout<<k/counter<<endl;
        }
    }
    return 0;
}