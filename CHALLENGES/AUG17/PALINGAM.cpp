#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		int arr[2][150]={0};
		for(int i=0;i<s1.length();i++){
            arr[0][s1[i]]+=1;
            arr[1][s2[i]]+=1;
		}
		int flag=0,count1=0,count2=0,s=0,t=0;
		for(int i=97;i<=122;i++){
			if(arr[0][i]!=0)
				s++;
			if(arr[1][i]!=0)
				t++;
			if(arr[0][i]>1 && arr[1][i]==0){
				flag=1;
				break;
			}
			if(arr[0][i]==0 && arr[1][i]!=0){
				count1++;
			}
			if(arr[0][i]!=0 && arr[1][i]==0){
				count2++;
			}
		}
		if(count1==0 && count2!=0){
			flag=1;
		}
        if(flag==1)
        	printf("A\n");
        else
        	printf("B\n");
	}
	return 0;
} 
