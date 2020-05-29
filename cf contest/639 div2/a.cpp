#include<stdio.h>

int main()
{
    int n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        if(m==1 || n==1)
            printf("YES\n");
        else if(n==2 && m==2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
