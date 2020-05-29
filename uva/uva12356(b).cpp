#include<stdio.h>
struct soldier
{
    long long int left;
    long long int right;
};
int main()
{
    long long int s,b,l,r,i;
    while(scanf("%lld %lld",&s,&b) && s && b)
    {
        struct soldier sd[s];
        sd[0].left=0;
        sd[0].right=1;
        sd[s-1].left=s-2;
        sd[s-1].left=s-1;
        for(i=1;i<s-1;i++)
        {
            sd[i].left=i-1;
            sd[i].right=i+1;
        }
        while(b--)
        {
            scanf("%lld %lld",&l,&r);

        }
    }
}

