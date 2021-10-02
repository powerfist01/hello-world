#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define int ll
#define INF 1e16
vector<int> z_function(string s){
    int n = (int) s.length();
    vector<int> z(n);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r)z[i] = min(r-i+1,z[i-l]);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])++z[i];
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    return z;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
          string s1,s2,x;
          cin>>s1>>s2>>x;
          x+='#';
          int n1 = s1.size(),n2=s2.size(),sz=x.size();
          vector<int> z1 = z_function(s1+'?'+x);
          z1 = vector<int>(z1.begin()+n1+1,z1.end());
          vector<int> z2 = z_function(s2+'?'+x);  
          z2 = vector<int>(z2.begin()+n2+1,z2.end());
          vector<vector<int>> rmq(sz,vector<int>(22,-INF));
          for(int i=0;i<sz;i++)rmq[i][0] = z2[i]+i;
          for(int j=1;j<22;j++)
            for(int i=0;i+(1<<j)<=sz;i++)
                rmq[i][j] = max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
        auto rmq_query = [&](int l,int r){
            int j = __lg(r-l+1);
            return max(rmq[l][j],rmq[r-(1<<j)+1][j]);
        };
        int ans = 0;
        for(int L=sz-1;L>=0;L--){
            int v = L+z1[L];
            int R_L = rmq_query(L,v);
            ans+=R_L-L;
        }
        cout<<ans<<"\n";
    }
    return 0;
} 

