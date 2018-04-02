#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int fingers[n],sheath[n];
		for(int i=0;i<n;i++){
			cin>>fingers[i];
		}
		for(int i=0;i<n;i++){
			cin>>sheath[i];
		}
		bool front = true, back = true;

		for(int i=0;i<n;i++){
			if(fingers[i]>sheath[i])
				front=false;
			if(fingers[n-i-1]>sheath[i])
				back=false;
		}

		if(front==true){
			if(back==true)
				cout<<"both\n";
			else
				cout<<"front\n";
		}
		else if(back==true){
			cout<<"back\n";
		}
		else
			cout<<"none\n";
	}
	return 0;
}