#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int arr[6];
		for(int i=1;i<=5;i++){
			cin>>arr[i];
		}
		int p;
		cin>>p;
		int total = 0;
		bool flag = true;
		for(int i=1;i<=5;i++){
			total += arr[i]*p;
		}
		cout<<total<<endl;
		if(total>120)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}