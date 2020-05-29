#include<stdio.h>
int main()
{
    int a,n,i,mx;
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    scanf("%d",&mx);
    n--;
    printf("%d ",mx);
    while(n--)
    {
        scanf("%d",&a);
        printf("%d ",a+mx);
        if(a+mx>mx)
            mx=a+mx;
    }
    printf("\n",mx);
}
