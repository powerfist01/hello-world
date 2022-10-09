#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int t;
	cin>>t;
	while(t--){
		long long int n,m,q;
		cin>>n>>m>>q;
		map <long long int,long long int> arr,brr;
		while(q--){
			int x,y;
			cin>>x>>y;
			if(!arr[x])
				arr[x] = 1;
			else{
				int z = arr[x];
				arr[x] = z+1;
			}

			if(!brr[y])
				brr[y] = 1;
			else{
				int z = brr[y];
				brr[y] = z+1;
			}	
		}
		long long int counter = 0,total = 0;
		map <long long int,long long int> :: iterator it;
		for(it=arr.begin();it!=arr.end();it++){
			if((it->second)%2 != 0){
				counter ++;
				total += m;
			}
		}
		for(it=brr.begin();it!=brr.end();it++){
			if((it->second)%2 != 0){
				total += n-2*counter;
			}
		}
		cout<<total<<endl;
	}
	return 0;
}