#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,k,i,j;
    char st[100005],first[100005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        scanf("%s",st);
        sort(&st[0],&st[n]);

        first[0]=st[0];
        if(st[k-1]>first[0])
            printf("%c\n",st[k-1]);
        else if(st[k]==st[n-1])
        {
            j=1;
            i=(n-k)/k;
            if((n-k)%k!=0)
                i++;
            while(i--)
                first[j++]=st[k];
            first[j]='\0';
            printf("%s\n",first);
        }
        else
        {
            printf("%c",first[0]);
            for(i=k;i<n;i++)
                printf("%c",st[i]);
            printf("\n");
        }
    }
    return 0;
}
