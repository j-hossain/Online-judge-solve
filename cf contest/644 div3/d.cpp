#include<stdio.h>
#include<math.h>

int main()
{
    int n,k,i,t,ans,sq,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        if(n<=k)
        {
            printf("1\n");
            continue;
        }
        else if(k==1)
        {
            printf("%d\n",n);
            continue;
        }

        ans=0;
        flag=0;
        sq = sqrt(n);
        for(i=2;i<=sq && i<=k;i++)
        {
            if(n%i==0)
            {
                flag=1;
                if(ans==0 || n/i<ans)
                    ans=n/i;
                if(n/i<=k)
                {
                    if(i<ans)
                        ans=i;
                }
            }
        }
        if(!flag)
            ans=n;
        printf("%d\n",ans);
    }
    return 0;
}
