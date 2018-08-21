#include <bits/stdc++.h>
using namespace std;
int main(){
	int p,s;
	cin>>p>>s;
	vector <int> v[10100];
	for(int k=1;k<=p;k++){
		int score[101],temp[101];
	   	for(int i=0;i<=100;i++){
	   		score[i]=0;
	   		temp[i]=0;
	   	}
		for(int i=1;i<=s;i++){
			cin>>temp[i];
		}
		for(int i=1;i<=s;i++){
			cin>>score[temp[i]];
		}

		int counter=0;
		for(int i=1;i<=100;i++){
			for(int j=i+1;j<=100;j++){
				if(score[j]!=0){
					if(score[i]>score[j]){
						counter++;
					}
					break;
				}
			}
		}
		v[counter].push_back(k);
		//cout<<counter<<" "<<v[counter][0]<<endl;
	}
	for(int i=0;i<=100;i++){
		if(!(v[i].empty())){
			//cout<<"Counter is: "<<i<<"  ";
			sort(v[i].begin(),v[i].end());
			for(int j=0;j<v[i].size();j++)
				cout<<v[i][j]<<endl;
		}
	}
	return 0;
}