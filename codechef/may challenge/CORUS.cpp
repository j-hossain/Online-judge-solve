#include<stdio.h>
#include<string.h>

int dif(int a,int b)
{
    return a>b?(a-b):0;
}

int main()
{
    int t,n,q,c,alpha[26],i,j,cnt;
    char st[100005];

    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<26;i++)
            alpha[i]=0;

        scanf("%d %d",&n,&q);
        scanf("%s",st);

        for(i=0;st[i]!='\0';i++)
        {
            alpha[st[i]-'a']++;
        }

        for(i=0;i<q;i++)
        {
            cnt=0;
            scanf("%d",&c);

            for(j=0;j<26;j++)
            {
                if(alpha[j]>c)
                cnt+=(alpha[j]-c);
            }

            printf("%d\n",cnt);
        }
    }
    return 0;
}
