#include<stdio.h>
int main()
{
    int n,arr[101],p;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p);
        arr[p]=i;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
