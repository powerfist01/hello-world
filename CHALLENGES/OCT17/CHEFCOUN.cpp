#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,a=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			if(i<=92681){
				cout<<a<<" ";
				a++;
			}
			else{
				cout<<"2 ";
			}
		}
		printf("\n");
	}
	return 0;
}