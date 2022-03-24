#include<stdio.h>
int main()
{
    int n,t,number;
    int mx,mn;
    scanf("%d",&t);
    while(t--)
    {
        mx=0;
        mn=100;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&number);
            if(number<mn)
                mn=number;
            if(number>mx)
                mx=number;
        }
        printf("%d\n",(mx-mn)*2);
    }
    return 0;
}
