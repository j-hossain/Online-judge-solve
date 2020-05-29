#include<stdio.h>
int d(int a,int b)
{
    if(a-b<0)
        return b-a;
    return a-b;
}
int main()
{
    int a,b,n,q,t,i;
    long long int sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        i=0;
        sum=0;
        while(q--)
        {
            scanf("%d %d",&a,&b);
            sum+=(d(i,a)+d(a,b));
            i=b;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
