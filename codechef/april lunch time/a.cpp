#include<stdio.h>
int main()
{
    int n,s,d,f,price[106],t,type,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&s);
        for(i=0;i<n;i++)
            scanf("%d",&price[i]);
        d=f=102;
        for(i=0;i<n;i++)
        {
            scanf("%d",&type);
            if(type)
            {
                if(price[i]<d)
                    d=price[i];
            }
            else
            {
                if(price[i]<f)
                    f=price[i];
            }
        }

        if(f+d<=100-s)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
