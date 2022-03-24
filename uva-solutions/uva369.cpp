#include<stdio.h>
#include<string.h>

#define li long long int

li comb[101][101];

li com(li n, li m)
{
    if(m==0 || n==m)return 1;
    if(comb[n][m]!=-1)return comb[n][m];

    comb[n][m]=com(n-1,m)+com(n-1,m-1);
    return comb[n][m];

}
int main()
{
    li n,m;
    memset(comb,-1,sizeof(comb));
    while(scanf("%lld %lld",&n,&m) && (n||m))
    {
        printf("%lld things taken %lld at a time is %lld exactly.\n",n,m,com(n,m));
    }
    return 0;
}
