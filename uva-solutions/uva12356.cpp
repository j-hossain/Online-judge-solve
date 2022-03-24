#include<stdio.h>
int main()
{
    long long int s,b,l,r,dead=1,flag,i;
    while(scanf("%lld %lld",&s,&b) && s && b)
    {
        int line[s]={};
        while(b--)
        {
            scanf("%lld %lld",&l,&r);
            for(i=l-1;i<r;i++)
                line[i]=dead;
            flag=0;
            l--;
            while(l--)
            {
                if(line[l]!=dead)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                printf("%lld ",l+1);
            else
                printf("* ");
            for(i=r;i<s;i++)
            {
                if(line[i]!=dead)
                    break;
            }
            if(i>=s)
                printf("*\n");
            else
                printf("%lld\n",i+1);
        }
        printf("-\n");
    }
    return 0;
}
