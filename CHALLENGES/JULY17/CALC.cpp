#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,b,ch,a;
		scanf("%lld%lld",&n,&b);
		ch=n/b;
		if(n<=b)
			printf("0");
		else if(n<=2*b)
			printf("%lld",n-b);
		else
		{
			a=ch/2;
			if(ch%2!=0)
                a++;
            printf("%lld",(n-a*b)*a);
		}
		printf("\n");
	}
	return 0;
} 
