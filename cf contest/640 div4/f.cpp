#include<stdio.h>
int main()
{
    int a,b,c,i;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(b==0)
        {
            if(c)
                c++;
            if(a)
                a++;
        }
        for(i=1;i<=c;i++)
            printf("1");
        for(i=1;i<=(b+1)/2;i++)
            printf("10");
        for(i=1;i<=a;i++)
            printf("0");
        if(!(b%2) && b>0)
            printf("1");
        printf("\n");
    }
    return 0;
}
