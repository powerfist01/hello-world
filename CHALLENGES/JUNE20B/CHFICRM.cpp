#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int five = 0,ten = 0;
        bool flag = true;
        for(int i=0;i<n;i++){
        	int x;
        	cin>>x;
        	if(x == 5){
        		five ++;
        	} else if(x == 10){
        		if(five == 0){
        			flag = false;
        		} else {
        			five --;
        			ten ++;
        		}
        	} else {
        		if(ten == 0){
        			if(five < 2){
        				flag = false;
        			} else {
        				five -= 2;
        			}
        		} else {
        			ten --;
        		}
        	}
        }
        if(flag){
        	cout<<"YES\n";
        } else {
        	cout<<"NO\n";
        }
    }
    return 0;
}