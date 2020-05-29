#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int tc,i;
    scanf("%d",&tc);
    for(i=1;i<=tc;i++)
    {
        int j,n,a,b,c,d,e;
        scanf("%d",&n);
        for(j=2;j<=n/2;j++)
        {
            if(n%j==0)
            {
                printf("%d\n",j);
                a=j;
                b=n/a;
                continue;
            }
            if(j!=a && n%j==0)
            {
                c=j;
                d=n/c;
                break;
            }

        }
        printf("Case #%d: %d = %d * %d = %d * %d\n",i,n,a,b,c,d);

    }
    return 0;
}
