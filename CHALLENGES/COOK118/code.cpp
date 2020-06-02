#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[1001];
		for(int i=1;i<1000;i++){
			arr[i]=0;
		}
		bool flag = true;
		int prev = 0;
		for(int i=0;i<n;i++){

			int temp;
			cin>>temp;
			if(temp != prev && arr[temp] > 0){
				flag = false;
			}
			arr[temp]++;
			prev = temp;
		}
		set <int> s;
		for(int i=1;i<1000;i++){
			if(arr[i]!=0){
				int siz = s.size();
				s.insert(arr[i]);
				if(siz == s.size()){
					flag = false;
					break;
				}
			}
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}