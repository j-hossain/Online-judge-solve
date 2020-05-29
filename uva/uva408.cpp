#include<stdio.h>
int main()
{
    int mod,step,x,num[100001],random,cnt;
    while(scanf("%d %d",&step,&mod)!=EOF)
    {
        cnt=1;
        for(int i=0;i<100001;i++)
            num[i]=0;
        random=step%mod;
        while(random)
        {
            if(!num[random])
            {
                num[random]=1;
            cnt++;
            }
            random=(random+step)%mod;
        }
        printf("%d\n",cnt);
        if(mod==cnt)
        {
            printf("%10d%10d      Good Choice\n",step,mod);
        }
        else
            printf("%10d%10d      Bad Choice\n",step,mod);
        printf("\n");
    }
}
