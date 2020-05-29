#include<stdio.h>
#include<math.h>

int main()
{
    int a,num[10],i;
    scanf("%d",&a);
    for(i=2;i<10;i++)
        num[i]=0;
    if(a==0)
    {
        printf("10\n");
        return 0;
    }
    if(a<=9)
        printf("%d\n",a);
    else
    {
        i=9;
        while(log(a)>1 && a>1 && i>1)
        {
            while(!(a%i))
            {
                num[i]++;
                a/=i;
            }
            i--;
        }
        if(log(a)<1)
        {
            if(a>1)
                num[a]++;
            for(i=2;i<10;i++)
            {
                if(num[i])
                {
                    while(num[i]--)
                        printf("%d",i);
                }
            }
            printf("\n");
        }
        else
            printf("-1\n");
    }
    return 0;
}
