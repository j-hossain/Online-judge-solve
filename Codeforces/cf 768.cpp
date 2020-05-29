#include<stdio.h>
int main()
{
    int arr[100001],n,i,mx,mn,cnt;
    scanf("%d",&n);
    mx=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]<mn || i==0)
            mn=arr[i];
        if(arr[i]>mx)
            mx=arr[i];
    }
    cnt=n;
    for(i=0;i<n;i++)
    {
        if(arr[i]==mn || arr[i]==mx)
            cnt--;
    }
    printf("%d\n",cnt);
}
