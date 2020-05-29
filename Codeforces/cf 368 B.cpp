#include<stdio.h>
#include<string.h>

int main()
{
    int pos[100005],i,n,m,num[100005],temp,arr[100005];
    int cnt;
    memset(num,0,100005);
    memset(pos,0,100005);
    scanf("%d %d",&n,&m);
    cnt=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);

    }
    for(i=n;i>0;i--)
    {
        if(!num[arr[i]])
        {
            cnt++;
            num[arr[i]]=1;
        }

        pos[i]=cnt;
    }
    pos[0]=0;
    while(m--)
    {
        scanf("%d",&temp);
        printf("%d\n",pos[temp]);
    }
    return 0;
}
