#include<stdio.h>
int main()
{
    int n,i,cnt,mx,prev,now;
    scanf("%d",&n);
    scanf("%d",&prev);
    cnt=1;
    mx=0;
    for(i=1;i<n;i++)
    {
        scanf("%d",&now);
        if(now<prev)
        {
            if(cnt>mx)
                mx=cnt;
            cnt=1;
        }
        else
            cnt++;
        prev=now;
    }
    if(cnt>mx)
        mx=cnt;
    printf("%d\n",mx);
    return 0;
}
