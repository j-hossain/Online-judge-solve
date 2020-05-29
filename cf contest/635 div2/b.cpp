#include<stdio.h>

int re(int h,int a,int b)
{
    int r1,r2;
    //printf("%d\n",h);
    if(h<=0)
        return 1;
    if(a==0 && b==0 && h>0)
        return 0;
    if(a>0 && b>0)
        return re(h/2+10,a-1,b)+re(h-10,a,b-1);
    if(a>0 && b==0)
        return re(h/2+10,a-1,b);
    if(b>0 && a==0)
        return re(h-10,a,b-1);

}

int main()
{
    int t,h,a,b,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&h,&a,&b);
        ans=re(h,a,b);
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
