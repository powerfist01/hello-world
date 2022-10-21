#include<stdio.h>
void main()
{
    int a[10],i,j,temp,n;
    printf("enter length of array");
    scanf("%d",&n);
    printf("enter array elements\n ");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {   
            if(a[j]>a[j+1])
            {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            }
        
        }
    }
    for(j=0;j<n;j++)
    {
        printf("%d",a[j]);
    }
}