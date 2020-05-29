#include<stdio.h>

int main()
{
    int t,n,sum,flag,x,i;
    scanf("%d",&t);
    while(t--)
    {
        flag=1;
        sum=0;
        scanf("%d",&n);
        while(n>0 &&flag)
        {
            for(i=1;i<n;i++)
            {
                x=(i*(3*i+1))/2;
                if(x>n)
                    break;
            }
            i--;
            x=(i*(3*i+1))/2;
            if(i==0)
                flag=0;
            else
            {
                sum++;
                n-=x;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
