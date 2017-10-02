#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long int n,m,total=0,salary=0,left=0;
		vector <pair<long long int,long long int> >v;
		set <long long int> s;
		scanf("%lld%lld",&n,&m);
		long long int a[n];
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		long long int x,y;
        for(int i=0;i<m;i++){
            scanf("%lld%lld",&x,&y);
            v.push_back(make_pair(x,y));
        }
        char qual[n][m];
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		cin>>qual[i][j];
        	}
        }
        for(int i=0;i<n;i++){
            int max=0,flag=-1;
        	for(int j=0;j<m;j++){
                if(qual[i][j]=='1' && a[i]<=v[j].first && v[j].second>0){
                    if(max<v[j].first){
                    	max=v[j].first;
                    	flag=j;
                    }
                }
        	}
            if(flag!=-1){
            	total+=1;
            	salary+=max;
            	v[flag].second--;
            	s.insert(flag);
            }
        }
        left=m-s.size();
        printf("%lld %lld %lld\n",total,salary,left);
	}
	return 0;
} 
