#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;;

int main()
{
    int arr[100005],i,n,flag=0;

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    sort(arr,arr+n);

    for(i=n;i>2;i--)
        if(arr[i-2]+arr[i-3]>arr[i-1])
            flag=1;
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
