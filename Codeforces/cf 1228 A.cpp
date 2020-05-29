#include<stdio.h>

int main()
{
    int mid,l,h,n,d,t,flag,temp;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d %d",&n,&d);
        if(d<=n)
        {
            printf("YES\n");
            continue;
        }

        l=1;
        h=n-1;
        while(l<=h)
        {
            mid=(l+h)/2;
            temp=mid+1;
            if(d%temp)
                temp=d+(temp-(d%temp));
            else
                temp=d;
            //printf("%d %d\n",mid,temp);
            temp=mid+(temp/(mid+1));
            if(temp<=n)
            {
                flag=1;
                break;
            }
            else
                h=mid-1;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
