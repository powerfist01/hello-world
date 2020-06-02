#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int total = 0;
		int k = s.length()-1;
		k/=2;
		int i1=0,i2=1,i3=1,i4=1,i5=2,i6,i7,i8=s.length()-1;
		i6=s.length()/2;
		i6--;
		i7=i6+2;
		while(k--){
			string s1(s,i1,i2),s2(s,i3,i4),s3(s,i5,i6),s4(s,i7,i8);
			if(s1==s2 && s3==s4){
				total++;
			}
			i2++;
			i3++;
			i4++;
			i5+=2;
			i6--;
			i7++;
		}
		cout<<total<<endl;
	}
	return 0;
}