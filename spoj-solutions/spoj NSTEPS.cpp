#include<stdio.h>
int main()
{
    int x,y,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&x,&y);
        if(x<y || (x+y)%2 || x-y>2)
            printf("No Number\n");
        else
            printf("%d\n",(x+y)-(x%2));
    }
    return 0;
}
