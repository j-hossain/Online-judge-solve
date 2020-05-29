#include<stdio.h>
int main()
{
    int t,a,b,c,d,x,y,x1,y1,x2,y2,p,q,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        scanf("%d %d %d %d %d %d",&x,&y,&x1,&y1,&x2,&y2);
        a*=(-1);
        c*=(-1);
        p=a+b;
        q=c+d;
        flag=0;
        if(a || b)
        {
            if(x!=x1 || x!=x2)
                flag++;
        }
        else
            flag++;
        if(c || d)
        {
            if(y!=y1 || y!=y2)
                flag++;
        }
        else
            flag++;

        if(x+p<=x2 && x+p>=x1 && y+q<=y2 && y+q>=y1 && flag==2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
