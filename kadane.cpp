#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll int t;
    cin>>t;
    while(t--){
    	ll int n;
    	cin>>n;
    	ll int a[n];
    	for(ll int i=0; i<n; i++){
    		cin>>a[i];
    	}
    	ll int max1=0, max2=0;
    	for(ll int i=0; i<n; i++){
    		if(a[i] > 0){
    			max2 += a[i];
    		}
    		if(max2 > max1)
    			max1 = max2;
    		if(max2 < 0 || a[i] < 0){
    			max2 = 0;
    		}
    	}
    	cout<<max1<<endl;
    }
}
