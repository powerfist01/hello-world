#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long int arr[n+1],prefix[n+1]={0};
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			prefix[i]=prefix[i-1]+arr[i];
		}

		cout<<upper_bound(prefix+1,prefix+n+1,100)-prefix;

		
		cout<<endl;
	}
	return 0; 
}