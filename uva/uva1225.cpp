#include<stdio.h>
int digit[10],n,t,x,temp;
int main()
{

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(x=1;x<=n;x++)
        {
            temp=x;
            while(temp)
            {
                digit[temp%10]++;
                temp/=10;
            }
        }
        for(x=0;x<10;x++)
        {
            if(x>0)
                printf(" ");
            printf("%d",digit[x]);
            digit[x]=0;
        }
        printf("\n");
    }
    return 0;
}
