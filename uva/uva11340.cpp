#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,k,m,i,v,temp,l,cn;
    double d;
    char text,s,c;
    scanf("%d",&n);
    while(n--)
    {
        cn=0;
        int s[10000]={};
        scanf("%d",&k);
        getchar();
        while(k--)
        {
            scanf("%c %d",&c,&v);
            getchar();
            temp=c;
            s[temp]=v;
        }
        scanf("%d",&m);
        getchar();
        i=0;
        while(1)
        {
                scanf("%c",&text);
                temp=text;
                if(temp)
                {
                    cn+=s[temp];
                }
                if(temp=='\n')
                {
                    i++;
                    if(i==m)
                        break;
                }
        }
        d=cn/100.00;
        printf("%.2lf$\n",d);
    }
    return 0;
}
