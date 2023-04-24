#include <iostream>
using namespace std;
bool isPrime(int a){
   for(int div=2;div<=a/2;div++){
        if(a%div==0){
            return false;
        }
    }
    return true;
}
int main() {
	int t;
	cin>>t;
	while(t>0){
	    int a,b;
	    cin>>a>>b;
	    int sum=a+b;
	    int i=1;
	 
	    sum+=i;
	    while(!isPrime(sum)){
	        i++;
	        sum++;
	    }

	  cout<<i<<endl;
	    t--;
	}
	return 0;
}
