#include <bits/stdc++.h>
using namespace std;
int c[1000];
const int inf=1e9;
int main(){
	memset(c,0,sizeof c);
	int k;
	cin>>k;
	int d[k];
	for(int i=0;i<k;i++){
		cin>>d[i];
	}
	int t;
	cin>>t;
	while(t--){
		int n,m=0,coin,ans=0;
		cin>>n;
        for(int p=1;p<=n;p++){
            m=inf;
            for(int j=0;j<k;j++)
            {
            	if(d[j]<=p && 1+c[p-d[j]]<m){
            		m=1+c[p-d[j]];
            		coin=j;
            	}
            }
            c[p]=m;
        }
        cout<<c[n]<<endl;
	}
	return 0;
}