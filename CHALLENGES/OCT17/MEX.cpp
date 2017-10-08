#include <bits/stdc++.h>
using namespace std;
#define siz 200007
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		bool arr[siz];
		memset(arr,false,sizeof arr);
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			arr[x]=true;
		}

		int count=0;
		for(int i=0;i<siz;i++){
			if(arr[i]==false)
				count++;
			if(count==k+1){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}