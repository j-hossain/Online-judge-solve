#include<stdio.h>

int main()
{
    int t,n,ans[201],i,j,l,temp,ar;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<201;i++)
            ans[i]=0;
        temp=n;
        i=0;
        while(temp)
        {
            ans[i++]=temp%10;
            temp/=10;
        }
        l=i;
        for(i=n-1;i>1;i--)
        {
            ar=0;
            for(j=0;j<l;j++)
            {
                ans[j]*=i;
                ans[j]+=ar;
                ar=ans[j]/10;
                ans[j]%=10;
            }
            while(ar)
            {
                ans[l]=ar%10;
                ar=ar/10;
                l++;
            }
        }
        for(i=l-1;i>=0;i--)
            printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}
