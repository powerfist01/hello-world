#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            if(n%2!=0 && i>=n-1){
                if(i==n-1)
                    cout<<n<<" ";
                else
                    cout<<n-2<<" ";
            }
            else{
                if(i%2!=0)
                    cout<<i+1<<" ";
                else
                    cout<<i-1<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
} 
