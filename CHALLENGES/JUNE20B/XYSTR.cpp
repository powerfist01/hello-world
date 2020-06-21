#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int all = 0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i] != s[i+1]){
                all ++;
                i++;
            }
        }
        cout<<all<<endl;
    }
    return 0;
}