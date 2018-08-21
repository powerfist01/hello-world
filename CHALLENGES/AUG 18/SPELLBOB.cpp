#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		int b=0,cnt=0,o=0;
		for(int i=0;i<3;i++){
			if(s1[i]=='b' || s2[i]=='b')
				b++;
			if(s1[i]=='o' || s2[i]=='o')
				o++;
			if((s1[i]=='b' && s2[i]=='o') || (s1[i]=='o' && s2[i]=='b'))
				cnt++;
		}
		if(b>=3 && o>=1)
			cout<<"yes";
		else if(b<2 || o<1)
			cout<<"no";
		else if(b==2 && o==1 && cnt==0)
			cout<<"yes";
		else if(b==2 && o==1 && cnt==1)
			cout<<"no";
		else if(b==2 && o==2 && cnt==2)
			cout<<"no";
        else
            cout<<"yes";
		cout<<endl;
 
	}
	return 0;
}