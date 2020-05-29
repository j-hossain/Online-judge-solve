#include<stdio.h>
#include<string.h>

int main()
{
    int lenght,p,i,t;
    char st[101];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&lenght);
        scanf("%s",st);
        p=-1;
        for(i=0;i<lenght;i++)
        {
            if(st[i]=='8')
            {
                p=i+1;
                break;
            }
        }
        if(p==-1 || lenght-p<10)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
