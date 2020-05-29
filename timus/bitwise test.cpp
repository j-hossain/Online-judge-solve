#include<stdio.h>

int main()
{
    int a,b,ans;

    while(1)
    {
        scanf("%d %d",&a,&b);
        ans=a^b;
        printf("%d\n",ans);
    }
}
