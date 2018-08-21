#include <bits/stdc++.h>
using namespace std;
#define siz 100
long long int arr[siz];
int main(){
	int t;
	cin>>t;
	arr[0]=1;
	arr[1]=2;
	for(int i=2;i<=30;i++){
		arr[i]=2*arr[i-1];
	}
	
	vector <long long int > v;
	for(int i=0;i<=30;i++){
		for(int j=i+1;j<=30;j++){
			v.push_back(arr[i]+arr[j]);
		}
	}

	sort(v.begin(),v.end());
	
	while(t--){
		long long int n;
		cin>>n;
		if(n==1)
			cout<<"2\n";
		else if(n==2)
			cout<<"1\n";
		else{
			if(binary_search(v.begin(),v.end(),n))
				cout<<"0\n";
			else{
				for(int i=1;i<=464;i++){
					if(n>v[i-1] && n<v[i]){
						int sub=0;
						sub=min(n-v[i-1],v[i]-n);
						cout<<sub<<endl;
					}
				}
			}
		}
	}
	return 0;
}