#include<stdio.h>

int main()
{
    int n,i,j,sum[20008],flag,arr[102],temp,tk;
    tk=0;

    while(scanf("%d",&n)!=EOF)
    {
        flag=0;
        tk++;

        for(i=0;i<20008;i++)
            sum[i]=0;
        scanf("%d",&arr[0]);
        if(arr[0]<1)
            flag=1;
        for(i=1;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]<=arr[i-1] || arr[i]<1)
                flag=1;
        }
        if(flag==0)
        {
            for(i=0;i<n;i++)
            {
                for(j=i;j<n;j++)
                {
                    temp=arr[i]+arr[j];

                    if(sum[temp]!=0)
                        flag=1;
                    sum[temp]=1;
                }
            }
        }

        if(!flag)
            printf("Case #%d: It is a B2-Sequence.\n",tk);
        else
            printf("Case #%d: It is not a B2-Sequence.\n",tk);

        printf("\n");
    }
    return 0;
}
