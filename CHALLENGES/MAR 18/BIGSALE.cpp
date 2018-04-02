#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		double loss=0,total=0;
		cin>>n;
		for(int i=0;i<n;i++){
			double price,quantity,discount;
			cin>>price>>quantity>>discount;
			loss=price;
			price+=(discount/100)*price;
			price-=(discount/100)*price;
			loss=loss-price;
			loss*=quantity;
			total+=loss;
		}
		printf("%.6f\n",total);
	}
	return 0;
}