#include<stdio.h>
#include<math.h>
int main()
{
    int t,n,i,k,arr[109];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        if(k>n)
        {
            printf("NO\n");
            continue;
        }
        if(!(n%2))
        {
            if(k<=n/2)
            {
                printf("YES\n");
                i=1;
                while(i<k)
                {
                    printf("2 ");
                    i++;
                }
                i--;
                printf("%d\n",n-(i*2));
            }
            else if(!(k%2))
            {
                printf("YES\n");
                i=1;
                while(i<k)
                {
                    printf("1 ");
                    i++;
                }
                i--;
                printf("%d\n",n-(i));
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            if(!(k%2))
            {
                printf("NO\n");
                continue;
            }

            printf("YES\n");
            i=1;
            while(i<k)
            {
                printf("1 ");
                i++;
            }
            i--;
            printf("%d\n",n-(i));
        }
    }
    return 0;
}
