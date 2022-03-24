#include<stdio.h>
#include<string.h>

int main()
{
    int n,l,m,i,k,mx,j;
    char s[1001],c;
    while(1)
    {
        scanf("%d",&n);
        if(!n)
            break;
        scanf("%s",s);
        l=strlen(s);
        m=l/n;
        for(i=0;i<n;i++)
        {
            mx=i*m;
            for(j=mx,k=m-1;k>=0;k-=2,j++)
            {
                c=s[j];
                s[j]=s[j+k];
                s[j+k]=c;
            }
        }
        printf("%s\n",s);
    }
    return 0;
}
