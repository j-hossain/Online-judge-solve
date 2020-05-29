#include<stdio.h>
int main()
{
    int pos[101],num,i,n,j,t;
    scanf("%d",&t);
    while(t--)
    {
        j=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num);
            if(num)
                pos[j++]=i;
        }
        for(i=1;i<j;i++)
        {
            if(pos[i]-pos[i-1]<6)
                break;
        }
        if(i<j)
            printf("NO\n");
        else
            printf("YES\n");
    }

}
