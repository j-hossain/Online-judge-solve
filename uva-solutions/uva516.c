#include<stdio.h>
#include<string.h>
int main()
{
    char c[50001];
    int a[5001],b[5001],i=0,st,j;
    while(1)
    {
        scanf("%[^\n]",c);
        if(c=="0")
            break;
        st=strlen(c);
        for(i=0,j=0;i<st;i+=4,j++)
        {

            a[j]=c[i]-48;
            b[j]=c[i+2]-48;
        }
        for(i=0;i<j;i++)
            printf("%d %d\n",a[i],b[i]);
    }
}

