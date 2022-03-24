#include<stdio.h>
int main()
{
    int a[1001],cnt,n,i,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        cnt=0;
        for(i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(a[j]<=a[i])
                    cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
