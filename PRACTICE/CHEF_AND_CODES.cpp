#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	
	ll t;
	cin>>t;
	
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	
	while(t--)
	{
	    string a,b;
        cin>>a;
        cin.get();
        getline(cin, b);
        
	    map<char,ll>c;
	    for(ll i=0;i<b.size();i++)
	    {
	        if(a.find(tolower(b[i]))!=string::npos)
                c[tolower(b[i])]++;
	    }
	    vector<pair<ll,char>>d;
	    
	    for(auto i=c.begin();i!=c.end();i++)
	    {
	        d.push_back(make_pair(i->second,i->first));
	    }
	    sort(d.begin(),d.end());
	    map<char,char>e;
	    
	    for(auto i=d.begin();i!=d.end();i++)
	    {
	        e[i->second]=a[26-d.size()+(i-d.begin())];
	    }
	    
	    for(ll i=0;i<b.size();i++)
	    
	    {
	        if(a.find(tolower(b[i]))!=string::npos)
	        {
	            if(b[i]==tolower(b[i]))
	            {
    	            cout<<e[tolower(b[i])];
	            }
    	        else
    	        {
    	            cout<<(char)toupper(e[tolower(b[i])]);
    	        }
	        }
	        else 
	        {
	            cout<<b[i];
	        }
	        
	    }
	    
	    cout<<endl;
    }
	return 0;
}
