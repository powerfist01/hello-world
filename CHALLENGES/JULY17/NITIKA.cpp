#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string str;
        int count=0,one=0,two=0;
        getline(cin>>std::ws,str);
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ')
                count++;
            if(str[i]==' ' && count==1)
                one=i+1;
            if(str[i]==' ' && count==2)
                two=i+1;
        }
        if(count==0)
        {
            printf("%c",toupper(str[0]));
            for(int i=1;i<str.size();i++)
            {
                printf("%c",tolower(str[i]));
            }
        }
        if(count==1)
        {
            printf("%c. %c",toupper(str[0]),toupper(str[one]));
            for(int i=one+1;i<str.size();i++)
            {
                printf("%c",tolower(str[i]));
            }
        }
        if(count==2)
        {
printf("%c. %c. %c",toupper(str[0]),toupper(str[one]),toupper(str[two]));
            for(int i=two+1;i<str.size();i++)
            {
                printf("%c",tolower(str[i]));
            }
        }
        printf("\n");
    }
    return 0;
} 
