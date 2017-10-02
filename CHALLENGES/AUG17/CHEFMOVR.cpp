#include <bits/stdc++.h>
using namespace std;
 
int main(){
	long long int t;
	scanf("%lld",&t);
	while(t--){
		long long int n,d,sum=0,flag=0,answer=0;
		scanf("%lld%lld",&n,&d);
		long long int a[n],check[d]={0},count[d]={0};
		for(long long int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
			check[i%d]+=a[i];
			count[i%d]+=1;
		}
		
		if(sum%n!=0){
			printf("-1\n");
			continue;
		}
		else{
			for(long long int i=0;i<d;i++){
				if(check[i]%count[i]!=0){
					flag=1;
					break;
				}
			}
			for(int i=0;i<d;i++){
				if(check[i]%count[i]!=0){
					flag=1;
					break;
				}
			}
			if(flag==1){
				printf("-1\n");
			    continue;
			}
 
			sum=sum/n;
 
		    for(long long int i=0;i<n;i++){
		    	long long int x=0;
                if(a[i]==sum){
                	//cout<<"equal\n";
                	continue;
                }
                else if(a[i]>sum){
                    //cout<<"more\n";
                    answer+=a[i]-sum;
                    //cout<<answer<<"more answer\n";
                    a[i+d]+=a[i]-sum;
                    //cout<<a[i+d]<<endl;
                    a[i]-=sum;
                    //cout<<a[i]<<"a[i]"<<endl;
                    continue;
                }
                else{
                    //cout<<"less\n";
                	long long int y=sum-a[i];
                    //cout<<y<<endl;
                    for(long long int j=i+d;j<n;j+=d){
                    	x+=1;
                    	//cout<<x<<"x"<<endl;
				        if(a[j]>y){
                            a[j]-=y;
                            //cout<<a[j]<<"a[j]\n";
                            answer+=x*y;
                            //cout<<answer<<"answer"<<endl;
                            break;
				        }
			        }
                }      
		    }
		}
		printf("%lld\n",answer);
	}
	return 0;
}  
