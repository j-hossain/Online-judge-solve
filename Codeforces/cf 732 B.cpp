#include<stdio.h>

int dif(int a,int b)
{
    return a>b?(a-b):0;
}
int main()
{
    int arr[500],i,n,k,temp,sum;
    int d1,d2;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sum=0;

    for(i=1;i<n;i++)
    {
        d1=dif(k,arr[i]+arr[i-1]);
        sum+=d1;
        arr[i]+=d1;
    }
    printf("%d\n",sum);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
