#include<stdio.h>
#include<ctype.h>

int main()
{
    int ar[27],i,cnt;
    char strng[1001];
    gets(strng);
    for(i=0;i<27;i++)
        ar[i]=0;
    for(i=0;strng[i]!='\0';i++)
    {
        if(isalpha(strng[i]))
            ar[strng[i]-'a']=1;
    }
    cnt=0;
    for(i=0;i<27;i++)
    {
        if(ar[i])
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
