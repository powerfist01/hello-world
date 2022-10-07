#include<bits/stdc++.h>
#include<string>
#define fast std::ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define  ll long long
using namespace std;
int a,n,b,t;
int main()
{
    fast;
      cin>>t;
     while(t--){
            cin>>a>>b>>n ;
     vector<bool>vec(6*1e5);
     int cur=1;
     vector<int>res;
     for(int i=1;i<=n;i++){
        while(vec[cur])cur++ ;
        res.push_back(cur);
        for(int i=0;i<res.size();i++){
                if(a*cur-b*res[i]>1)
           vec[a*cur-b*res[i]]=1;
        if(a*res[i]-b*cur>1)
           vec[a*res[i]-b*cur]=1;
        }
        cout<<cur++<<" ";
       }
        cout<<endl ;

     }

    return 0;
}
