#include<stdio.h>
int main()
{
    long long int a,b,n,s,q,i;
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&n,&s);
        if(s-(a*n)<=b && s%n<=b)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
