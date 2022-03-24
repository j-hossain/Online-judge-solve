#include<stdio.h>
#include<string.h>
int main()
{
    char c[50001];
    int a[5001],b[5001],i=0,st,j;
    while(1)
    {
        gets(c);
        if(c=="0")
            break;
        st=strlen(c);
        for(i=0,j=0;i<st;i+=4,j++)
        {
            printf("%d %c\n",i,c[i+2]);
            a[j]=c[i];
            b[j]=c[i+2];
        }
        for(i=0;i<j;i++)
            printf("%d %d\n",a[i],b[i]);
    }
}
