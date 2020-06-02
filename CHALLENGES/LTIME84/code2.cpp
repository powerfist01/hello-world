#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		long long int arr[n],brr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int i=0;i<n;i++){
			cin>>brr[i];
		}
		long long int current1 = 0,current2 = 0;
		long long int total = 0;
		for(int i=0;i<n;i++){
			if(current2 == current1){
				if(arr[i] == brr[i])
				total += arr[i];
			}
			current1 += arr[i];
			current2 += brr[i];

		}
		cout<<total<<endl;
	}
	return 0;
}