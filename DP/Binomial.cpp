#include<bits/stdc++.h>
using namespace std;
long long int arr[1000][1000];
int binomial(int n,int k){
	if(arr[n][k]!=0)
		return arr[n][k];
	if(n==k || k==0)
		return 1;
	else
		return arr[n][k]=binomial(n-1,k-1)+binomial(n-1,k);
}
int main(){
	memset(arr,0,sizeof arr[0][0]*1000*1000);
	int n,k;
	cin>>n>>k;
	cout<<binomial(n,k)<<endl;
	return 0;
}