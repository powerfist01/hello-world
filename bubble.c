#include<stdio.h>
#include<conio.h>
void main()
{
    int a[]={2,1,4,2,8};
    int i,j,temp=0;
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Sorted array");
    for(i=0;i<5;i++)
    {
        printf("%d",a[i]);
    }
}