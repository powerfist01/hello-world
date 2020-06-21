#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c,p,q,r;
		cin>>p>>q>>r>>a>>b>>c;
		int mnm = 100;

		set <int> s;
		if(a!=p)
			s.insert(a-p);
		if(b!=q)
			s.insert(b-q);
		if(c!=r)
			s.insert(c-r);
		mnm = s.size();
		cout<<mnm<<endl;
		int pdt = 0;
		if(a%p ==0){
			if(a==p){
				if(b%q == 0){
					if(b==q){
						if(c%r == 0){
							if(c==r){
								pdt = 0;
							} else {
								pdt = 1;
							}
						}
					} else {
						if(c%r == 0){
							if(c==r){
								pdt = 1;
							} else {
								if(b/q == c/r){
									pdt = 1;
								} else {
									pdt = 2;
								}
							}
						}
					}
				} else {
					//here
					if(b==q){
						if(c%r == 0){
							if(c==r){
								pdt = 0;
							} else {
								pdt = 1;
							}
						}
					} else {
						if(c%r == 0){
							if(c==r){
								pdt = 1;
							} else {
								if(b/q == c/r){
									pdt = 1;
								} else {
									pdt = 2;
								}
							}
						}
					}
					//here
				}
			}
		}
	}	
	return 0;
}