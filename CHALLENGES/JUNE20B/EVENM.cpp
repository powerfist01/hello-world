#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int temp = i*i;
            int counter = -1;
            for(int j=1;j<=n;j++){
                if(j<=i){
                    cout<<temp<<" ";
                    if(j+1 <= i)
                        temp --;
                } else {
                    temp += counter;
                    cout<<temp<<" ";
                }
                counter += 2;
            }
            cout<<endl;
        }
    }
    return 0;
}