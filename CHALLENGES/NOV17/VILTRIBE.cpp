#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int aa=0,bb=0,counter=0;
        char c='.';
        bool flag1=false,flag2=false;
        for(int i=0;i<s.length();i++){
        	if(s[i]=='A'){
        		aa++;
        		if(c=='A'){
        			aa+=counter;	
        		}
        		counter=0;
        	}
        	if(s[i]=='B'){
        		bb++;
        		if(c=='B'){
        			bb+=counter;
        		}
        		counter=0;
        	}
        	if(s[i]=='A' || s[i]=='B')
        		c=s[i];
        	if(s[i]=='.')
        		counter++;
        	//cout<<aa<<" "<<bb<<endl;
        }
        cout<<aa<<" "<<bb<<"\n";
    }
    return 0;
} 
