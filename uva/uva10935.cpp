#include<stdio.h>


typedef struct
{
    int p;//prev
    int n;//next
}card;

int main()
{
    card s[52];
    int next,prev;
    int n,i;

    while(scanf("%d",&n)&&n)
    {
        for(i=1;i<=n;i++)
        {
            s[i].p=i-1;
            s[i].n=i+1;
            if(i==1)
                s[i].p=n;
            if(i==n)
                s[i].n=1;
        }
        printf("Discarded cards:");
        i=1;
        while(n>1)
        {
            n--;
            prev=s[i].p;
            next=s[i].n;
            s[prev].n=next;
            s[next].p=prev;
            printf(" %d",i);
            if(n>1)
                printf(",");
            i=s[next].n;
            //printf("%d\n",n);
        }
        printf("\nRemaining card: %d\n",i);
    }
    return 0;
}
