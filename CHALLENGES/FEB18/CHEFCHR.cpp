#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		int counter = 0;
		for(int i=0;i<s.length();i++){
			set <char> ss;
			if(s[i]=='c' || s[i]=='C' || s[i]=='H' || s[i]=='h' || s[i]=='e' || s[i]=='E' || s[i]=='f' || s[i]=='F'){
				ss.insert(s[i]);
				for(int k=i+1;k<i+4;k++){
					if(s[k]=='c' || s[k]=='C' || s[k]=='H' || s[k]=='h' || s[k]=='e' || s[k]=='E' || s[k]=='f' || s[k]=='F'){
						ss.insert(s[k]);
					}
					else
						break;
				}
			}	
			if(ss.size()==4)
				counter++;
			ss.clear();
		}
		if(counter == 0)
			cout<<"normal\n";
		else
			cout<<"lovely "<<counter<<endl;
	}
	return 0;
}