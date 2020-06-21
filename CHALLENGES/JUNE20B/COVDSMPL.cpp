#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,p;
		cin>>n>>p;
		int arr[n+1][n+1];
		memset(arr,0,sizeof arr);
		int all;
		cout<<"1 1 1 "<<n<<" "<<n<<endl;
		cin>>all;
		if(all == 0){
			cout<<"2"<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cout<<arr[i][j]<<" ";
				}
				cout<<endl;
			}
			int temp;
			cin>>temp;
			if(temp == -1){
				return 0;
			} else {
				continue;
			}
		}

		set <int> s;
		for(int i=1;i<=n;i++){
			int total = 0;
			cout<<"1 "<<"1 "<<i<<" "<<n<<" "<<i<<endl;
			cin>>total;
			if(total == 0){
				s.insert(i);
			}
		}
		
		int cntr = 0;
		for(int i=1;i<=n;i++){
			if(cntr<all){
				int total = 0,cnt = 0;
				cout<<"1 "<<i<<" 1 "<<i<<" "<<n<<" "<<endl;
				cin>>total;
				for(int j=1;j<=n;j++){
					if(s.count(j) != 1){
						if(cnt < total){
							cout<<"1 "<<i<<" "<<j<<" "<<i<<" "<<j<<endl;
							int x;
							cin>>x;
							if(x==1){
								arr[i][j] = 1;
								cnt++;
								cntr++;
							} else {
								arr[i][j] = 0;
							}
						} else {
							arr[i][j] = 0;
						}
					} else {
							arr[i][j] = 0;
					}
				}
			} else {
				break;
			}
		}
		cout<<"2"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		int temp;
		cin>>temp;
		if(temp == -1){
			return 0;
		} else {
			continue;
		}
	}
	return 0;
}