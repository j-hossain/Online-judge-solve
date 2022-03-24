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
            n=b;
        if(is_prime(n))
        {
            p=1;
        }
        else
        {
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
        if(p==1)
            c=1;
        else if(b==1)
            c=0;
        else
        {
            for(i=0;i<j;i++)
            {
                for(k=i+1;k<j;k++){

                    if(a[k]==a[i])
                        a[k]=0;
                    else if(a[k]>a[i])
                        break;

                }

            }
            for(i=0;i<j;i++)
            {
                if(a[i]>0)
                    c++;
            }
        }
        printf("%lld : %lld\n",b,c);

    }
    return 0;
}

