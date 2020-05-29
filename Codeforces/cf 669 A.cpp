#include<stdio.h>
int main()
{
    int n;
    int ans;
    scanf("%d",&n);
    if(n%3)
        ans=1;
    else
        ans=0;
    ans+=(2*(n/3));
    printf("%d\n",ans);
    return 0;
}
