#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		set <int> s;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			s.insert(arr[i]);
		}
		if(s.size()==n){
			cout<<"0"<<endl;
			continue;
		}
		int total=0,same=1;
		sort(arr,arr+n);
		for(int i=1;i<n;i++){
			if(arr[i-1]==arr[i])
				same++;
			else{
				total+=same-1;
				same=1;
			}
		}
		total+=same-1;
		cout<<total<<endl;
	}
	return 0;
}