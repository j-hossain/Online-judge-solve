#include<stdio.h>
int main()
{
    int n,t,sum,i,p,arr[100005];
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        if((n/2)%2)
           {
               printf("NO\n");
               continue;
           }
        else
        {
            printf("YES\n");
            p=2;
            for(i=1;i<=n/2;i++)
            {
                arr[i]=p;
                printf("%d ",p);
                p+=4;
            }
            i=1;
            p=-1;
            while(i<=n/2)
            {
                printf("%d ",arr[i]-p);
                p=-p;
                i++;
            }
            printf("\n");

        }
    }
    return 0;
}
