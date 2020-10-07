    #include <bits/stdc++.h>
    #include <iostream.h>
    using namespace std;
    int main(){
        int t;
        cin>>t;
        while(t--){
            string a,b,c="";
            cin>>a>>b;
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            if(a.length()>=b.length()){
                for(int i=0;i<a.length();i++){
                    if(i<b.length()){
                        long long int z=int(a[i]-48)+int(b[i]-48);
                        z=z%10;
                        c+=z+48;
                    }
                    else
                        c+=a[i];
                }
            }
            else{
                for(int i=0;i<b.length();i++){
                    if(i<a.length()){
                        long long int z=int(a[i]-48)+int(b[i]-48);
                        z=z%10;
                        c+=z+48;
                    }
                    else
                        c+=b[i];
                }
            }
            reverse(c.begin(),c.end());
            bool flag=false;
            int counter=0;
            for(int i=0;i<c.length();i++){
                if(c[i]!='0')
                    flag=true;
                else
                    counter++;
                if(flag)
                    cout<<c[i];
            }
            if(counter==c.length())
                cout<<"0";
            cout<<endl;
        }
        return 0;
    } 
