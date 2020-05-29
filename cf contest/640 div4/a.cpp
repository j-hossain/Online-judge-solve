#include<stdio.h>

int main()
{
    int t,n,num,arr[10],i,div;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        i=0;
        div=10;
        while(n>0)
        {
            if(n%div!=0)
            {
                arr[i++]=n%div;
                n-=(n%div);
            }
            div*=10;
        }
        n=i;
        printf("%d\n",n);
        for(i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
            printf("\n");
    }
    return 0;
}
