#include<bits/stdc++.h>
using namespace std;
long long int fibb[1000000];
int fibonnaci(int n){
	if(fibb[n]!=0)
		return fibb[n];
	if(n==1)
		return 1;
	else if(n==2)
		return 1;
	else if(n==3)
		return 2;
	else
		return fibb[n]=fibonnaci(n-1)+fibonnaci(n-2);
}
int main(){
	memset(fibb,0,sizeof fibb);
	int n;
	cin>>n;
	cout<<fibonnaci(n)<<endl;
	return 0;
}
