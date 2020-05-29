#include<stdio.h>
int main()
{
    int n,i,j,arr[100005],t,dif[100005],temp,mx,cnt;
    scanf("%d",&t);
    while(t--)
    {
        mx=0;
        cnt=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        for(i=1,j=0;i<=n/2;i++)
        {
            temp=arr[i]+arr[n-i+1];
            if(mx==0 || temp<mx)
                mx=temp;
            dif[j++]=temp;
            printf("%d\n",dif[j-1]);
        }
        for(i=0;i<j;i++)
        {
            if(dif[i]!=mx)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
