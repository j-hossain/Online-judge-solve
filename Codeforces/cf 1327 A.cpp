#include<stdio.h>
#include<math.h>
int main()
{
    long int n,k,t;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld %ld",&n,&k);
        if(n%2)
        {
            if(k%2)
            {
                if(sqrt(n)>=k || k==1)
                    printf("YES\n");
                else
                    printf("NO\n");
            }

            else
                printf("NO\n");
        }
        else
        {
            if(!(k%2))
                {
                    if(sqrt(n)>=k)
                        printf("YES\n");
                    else
                        printf("NO\n");
                }
            else
                printf("NO\n");
        }
    }
    return 0;
}
