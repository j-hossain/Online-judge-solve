#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,k,m,i,v,temp,l,cn,s[10000];
    double d;
    char text[10001],c[2];
    scanf("%d",&n);
    while(n--)
    {
        cn=0;
        for(i=0;i<10000;i++)
            s[i]=0;
        scanf("%d",&k);
        getchar();
        while(k--)
        {
            scanf("%s %d",&c,&v);
            getchar();
            temp=c[0];
            s[temp]=v;
        }
        scanf("%d",&m);
        getchar();
        while(m--)
        {
            gets(text);
            l=strlen(text);
            for(i=0;i<l;i++)
            {
                temp=text[i];
                if(temp)
                {
                    cn+=s[temp];
                }
            }
        }
        d=cn/100.00;
        printf("%.2lf$\n",d);
    }
    return 0;
}
