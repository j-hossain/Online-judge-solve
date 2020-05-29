#include<stdio.h>
#include<math.h>
typedef signed long long int  slli;
int is_prime(slli n)
{
    slli i;
    if(n==2 || n==3)
        return 1;
    else if(n==1)
        return 0;
    else
    {
        slli sq=sqrt(n);
        for(i=2;i<=sq;i++)
        {
            if(n%i==0)
                break;
        }
        if(i>sq)
            return 1;
        else
            return 0;
    }
}
int main()
{
    slli n,i,sq,a[5001],j,b,p,c,k;
    while(1)
    {
        j=0,p=0,c=0;
        scanf("%lld",&b);
        if(b==0)
            break;
        else
        {
            if(b<0)
                n=b*-1;
            else
                n=b;
            sq=sqrt(n);
            for(i=2,j=0;i<=sq;)
            {
                if(n%i==0 && is_prime(i))
                {
                    a[j]=i;
                    j++;
                    if(is_prime(n/i))
                    {
                        a[j]=n/i;
                        j++;
                        break;
                    }
                    n/=i;
                }
                else
                    i++;
            }
        }
        if(j==0 || a[0]==a[j-1])
            printf("-1\n");
        else
            printf("%lld\n",a[j-1]);

    }
    return 0;
}


