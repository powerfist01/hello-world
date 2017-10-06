#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int que,part;
		scanf("%d%d",&que,&part);
		int cake=0,hard=0;
		for(int i=0;i<que;i++){
			int x;
			scanf("%d",&x);
			if(x>=part/2)
				cake++;
			else if(x<=part/10)
				hard++;
		}
		if(cake==1 && hard==2)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}