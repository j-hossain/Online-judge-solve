#include<stdio.h>
#include<math.h>

int gcd(int a,int b)
{
    if(b!=0)
        return gcd(b,a%b);
    return a;
}
int main()
{
    int n,i,j,arr[100],cnt,c1;
    double ans;
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        cnt=0;
        c1=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                c1++;
                if(gcd(arr[i],arr[j])==1)
                    cnt++;
            }
        }
        if(!cnt)
        {
            printf("No estimate for this data set.\n");
            continue;
        }
        ans=(double)c1/cnt;
        ans*=6.0;
        ans=sqrt(ans);
        printf("%.6lf\n",ans);
    }
    return 0;
}
