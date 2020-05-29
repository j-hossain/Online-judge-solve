#include<stdio.h>
#include<iostream>
#include<algorithm
int main()
{
    long long int a[1005],mn,mx;
    int n,d,t,flag;
    double d;
    scanf("%d",&t);
    while(t--)
    {
        mn=mx=flag=0;
        scanf("%d %d",&n,&d);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            if(mn==0 || a[i]<mn)
                mn=a[i];
            if(a[i]>mx)
                mx=a[i];
        }
        if(n>=d)
            printf("0\n");
        else
        {
            if(d==3)
            {
                for(i=0;i<n;i++)
            {
                d=a[i]/2.0;
                for(j=0;j<n;i++)
                {
                    if(a[i]==d)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
                printf("1\n",);
            else
                printf("2\n");
            }
            else
                printf("1\n");

        }
        return 0;

    }
}
