#include<stdio.h>
int main()
{
    int id,sum,root,t,n;
    scanf("%d",&t);
    while(t--)
    {
        root=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d",&id,&sum);

            root+=(id-sum);
        }
        printf("%d\n",root);
    }
    return 0;
}
