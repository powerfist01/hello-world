#include<bits/stdc++.h>
using namespace std;
int t[1000];
int a[1000];
int main(){
	int n;
	void build(int,int,int);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	build(1,0,n-1);
	printf("%d",t[1]);
	
}
void build(int node,int low,int high){
	int mid;
	if(low==high)
	t[node]=a[low];
	else
	{
		mid=(low+high)/2;
		build(2*node,low,mid);
		build(2*node+1,mid+1,high);
		t[node]=t[2*node]+t[2*node+1];
	}
}
