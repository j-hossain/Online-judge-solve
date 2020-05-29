#include<stdio.h>
int main()
{
    int n,t,i=0;
    scanf("%d %d",&n,&t);
    char number[101];
    if(t<10)
    {
        for(i=0;i<n;i++)
            number[i]='0'+t;
    }
    else if(n>1)
    {
        for(i=0;i<n-1;i++)
            number[i]='1';
        number[i++]='0';
    }
    number[i]='\0';
    if(i>0)
    printf("%s\n",number);
    else
        printf("-1\n");
    return 0;
}
