#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        long long int n,sum=1000000000000,index=0;
        cin>>n;
        long long int arr[n+1]={0},pre[n+1]={0},suf[n+2]={0};
        for(long long int i=1;i<=n;i++){
            cin>>arr[i];
            pre[i]=pre[i-1]+arr[i];
        }
        for(long long int i=n;i>=1;i--){
            suf[i]=suf[i+1]+arr[i];

            if(sum>=pre[i]+suf[i]){
                sum=pre[i]+suf[i];
                index=i;
            }
        }
        cout<<index<<endl;
    }
    return 0;
} 
