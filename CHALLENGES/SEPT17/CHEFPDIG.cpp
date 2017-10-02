#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        string :: iterator it;
        set <char> s;
        int arr[10]={0};
        for(it=str.begin();it!=str.end();it++){
            if(arr[*it-48]<2)
                arr[*it-48]++;
        }
        int temp=0;
        for(int i=0;i<10;i++){
            if(arr[i]>0){  
                for(int j=0;j<10;j++){
                    temp=i;
                    temp*=10;
                    if(i==j && arr[j]==1)
                        continue;
                    if(arr[j]>0){
                        temp+=j;
                        if(temp>=65 && temp<=90)
                            s.insert(temp);
                    }
                } 
            }    
        }
        set <char> :: iterator is;
        for(is=s.begin();is!=s.end();is++){
            cout<<*is;
        }
        cout<<endl;
    }
    return 0;
} 
