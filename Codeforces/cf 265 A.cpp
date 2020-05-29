#include<stdio.h>
#include<string.h>

int main()
{
    char s[51],t[51];
    int p=1,i,lenght;
    scanf("%s",s);
    scanf("%s",t);
    lenght=strlen(t);
    for(i=0;i<lenght;i++)
    {
        if(s[p-1]==t[i])
            p++;
    }
    printf("%d\n",p);
    return 0;
}
