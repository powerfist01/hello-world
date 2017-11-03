#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        long long int aa=0,bb=0,count=0;
        char ch='.';
        for(long long int i=0;i<s.length();i++){
        	if(s[i]=='A'){
        		aa++;
        		if(ch=='A'){
        			aa+=count;	
        		}
        		counter=0;
        	}
        	if(s[i]=='B'){
        		bb++;
        		if(ch=='B'){
        			bb+=count;
        		}
        		counter=0;
        	}
        	if(s[i]=='A' || s[i]=='B')
        		ch=s[i];
        	if(s[i]=='.')
        		count++;
        	//cout<<aa<<" "<<bb<<endl;
        }
        cout<<aa<<" "<<bb<<"\n";
    }
    return 0;
} 
