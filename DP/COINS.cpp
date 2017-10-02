#include<bits/stdc++.h>
using namespace std;
map<int, long long> cmax;
long long getMax(int n) {
    if (cmax.find(n) != cmax.end())
		return cmax[n];
	long long result;
        if (n <= 2)
		result = n;
	else
    		result = getMax(n / 2) + getMax(n / 3) + getMax(n / 4);
	if (result < n)
        	result = n;
    	cmax[n] = result;
	return result;
    }
     
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
    	printf("%lld\n", getMax(n));
	} 	
	return 0;
    } 
