#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		string s;
		long long int i,count=0,max1=1,max2=1,ans=1;
		cin>>s;   
		for(i=0;i<s.length();++i)
		{
			if(s[i]=='<')
			{
				max1=1;
				while((s[i]=='<' || s[i]=='=') && i<s.length())
				{
					++i;
					if(s[i]!='=')
						++max1;
				}
				--i;
			}
			else if(s[i]=='>')
			{
				max2=1;
				while((s[i]=='>' || s[i]=='=') && i<s.length())
				{
					++i;
					if(s[i]!='=')
						++max2;
				}
				--i;
			}
			ans=max(max1,max(ans,max2));
		}
		cout<<ans<<endl;
    }
	return 0;
} 
