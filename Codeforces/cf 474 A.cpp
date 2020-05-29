#include<stdio.h>
#include<string.h>

int main()
{
    int board[1000],i,d,lenght;
    char key[]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/','\0'};
    for(i=0;i<30;i++)
    {
        board[key[i]]=i;
    }
    char s[101],dir[2];
    scanf("%s",dir);
    if(dir[0]=='R')
        d=-1;
    else
        d=1;
    scanf("%s",s);
    lenght=strlen(s);
    for(i=0;i<lenght;i++)
    {
        s[i]=key[board[s[i]]+d];
    }
    printf("%s\n",s);
}
