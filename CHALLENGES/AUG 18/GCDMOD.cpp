#include <bits/stdc++.h>
using namespace std;

int GCD(long long int A, long long int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long int a,b,n;
		cin>>a>>b>>n;
		cout<<GCD(pow(a,n)+pow(b,n),abs(a-b))<<endl;
	}
	return 0;
}