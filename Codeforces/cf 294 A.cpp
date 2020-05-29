#include<stdio.h>
int main()
{
    int birds[101],n,i,w,s,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&birds[i]);
    scanf("%d",&s);
    while(s--)
    {
        scanf("%d %d",&w,&b);
        if(w<n)
            birds[w+1]+=(birds[w]-b);
        if(w>1)
            birds[w-1]+=(b-1);
        birds[w]=0;
    }

    for(i=1;i<=n;i++)
        printf("%d\n",birds[i]);
    return 0;
}
