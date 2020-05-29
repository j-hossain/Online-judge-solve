#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,i,t,j;
    int arr[100005],ans[100005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);

        sort(arr+1,arr+n+1);
        i=(n+1)/2;
        j=0;
        while(i>0)
        {
            if(i!=n-i+1)
            {
                printf("%d ",arr[i]);
                printf("%d ",arr[n-i+1]);
            }
            else
            {
                printf("%d ",arr[i]);
            }
            i--;
        }
        printf("\n");
    }

}
