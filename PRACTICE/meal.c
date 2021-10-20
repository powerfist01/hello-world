#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--){
	    int n,cc=0,co=0,cd=0,ce=0,ch=0,cf=0,meal=0;
	    scanf("%d",&n);
	    while(n--){
	        char str[1000];
	        scanf("%s",str);
	        for(int i=0;i<strlen(str);i++){
	            if(str[i]=='c'){
	                cc++;
	            }
	            if(str[i]=='o'){
	                co++;
	            }
	            if(str[i]=='d'){
	                cd++;
	            }
	            if(str[i]=='e'){
	                ce++;
	            }
	            if(str[i]=='h'){
	                ch++;
	            }
	            if(str[i]=='f'){
	                cf++;
	            }
	        }
	    }
	    while(n--){
	        if((cc-2>=0)&&(co-1>=0)&&(cd-1>=0)&&(ce-2>=0)&&(ch-1>=0)&&(cf-1>=0)){
	            meal++;
	            cc=cc-2;
	            ce=ce-2;
	            co--;cd--;ch--;cf--;
	        }
	        else break;
	    }
	    printf("%d\n",meal);
	}
	return 0;
}

