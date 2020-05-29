#include<stdio.h>

int main()
{
    int t,n,i,cnt1,cnt2;
    int a[100001],b[100001];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);

        cnt1=cnt2=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==b[i])
            {
                if(a[i]==1)
                    cnt1=1;
                else if(a[i]==-1)
                    cnt2=1;
            }
            else
            {
                if(b[i]<a[i])
                {
                    if(!cnt2)
                    {
                        printf("NO\n");
                        break;
                    }
                    else
                    {
                        if(a[i]==1)
                            cnt1=1;
                    }
                }
                else
                {
                    if(!cnt1)
                    {
                        printf("NO\n");
                        break;
                    }
                    else
                    {
                        if(a[i]==-1)
                            cnt2=1;
                    }
                }
            }
        }
        if(i>=n)
            printf("YES\n");
    }
    return 0;
}
