#include<stdio.h>
int main()
{
    int a,b,i,j,ans;
    scanf("%d %d %d %d",&a,&i,&b,&j);
    ans=a;
    while(a<=b)
    {
        if(a+i<=b)
        {
            a+=i;
            ans=a;
        }
        else
        {
            ans=b;
            break;
        }
        if(a<=b-j)
        {
            b-=j;
            ans=b;
        }
        else
        {
            ans=a;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
