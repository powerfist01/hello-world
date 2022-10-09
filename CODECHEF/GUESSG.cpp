#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int left = 1, right = n;
	while(1){
		while(1){
			cout<<left<<endl;
			char c;
			cin>>c;
			if(c == 'L'){
				break;
			} else if(c == 'G'){
				left++;
			} else {
				return 0;
			}
			cout<<right<<endl;
			cin>>c;
			if(c == 'G'){
				break;
			} else if(c == 'L'){
				right--;
			} else {
				return 0;
			}
		}
		int mid = (left + right)/2;
		cout<<mid<<endl;
		char ch;
		cin>>ch;
		if(ch == 'G'){
			left = mid;
		} else if(ch == 'L'){
			right = mid;
		} else {
			return 0;
		}
	}
	return 0;
}