#include<stdio.h>

int main()
{
    int t,h,a,b,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&h,&a,&b);
        if(h<=b*10)
        {
            printf("YES\n");
            continue;
        }

        while(a>0 && h>0)
        {
            h=(h/2)+10;
            a--;
        }
        if(h<=b*10)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
