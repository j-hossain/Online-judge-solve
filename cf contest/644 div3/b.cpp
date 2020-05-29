#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int arr[55],i,n,t,dif,temp;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        dif=-1;
        for(i=1;i<n;i++)
        {
            temp=arr[i]-arr[i-1];
            if(temp<dif || dif==-1)
                dif=temp;
        }

        printf("%d\n",dif);
    }
    return 0;
}
