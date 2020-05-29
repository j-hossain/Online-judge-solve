#include<stdio.h>
int main()
{
    int arr[100001],n,mx,i,has[100001];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        has[arr[i]]=0;
    }
    mx=n;
    for(i=0;i<n;i++)
    {
        has[arr[i]]=1;
        if(arr[i]==mx)
        {
            while(has[mx])
                printf("%d ",mx--);
            printf("\n");
        }
        else
            printf("\n");
    }
    return 0;
}
