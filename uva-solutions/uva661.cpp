#include<stdio.h>
int main()
{
    int state[21],power[21],max_power,total_power,fuse,n,m,temp,t=0,i;
    while(scanf("%d %d %d",&n,&m,&fuse))
    {
        t++;
        if(n==0 && m==0 && fuse==0)
        {
            break;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&power[i]);
            state[i]=0;
        }
        max_power=total_power=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d",&temp);
            if(!state[temp])
            {
                total_power+=power[temp];
                state[temp]=1;
            }

            else
            {
                total_power-=power[temp];
                state[temp]=0;
            }

            if(total_power>max_power)
                max_power=total_power;
        }
        printf("Sequence %d\n",t);
        if(max_power>fuse)
            printf("Fuse was blown.\n");
        else
        {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n",max_power);
        }
        printf("\n");
    }
    return 0;
}
