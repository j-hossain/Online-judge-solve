#include<stdio.h>
#include<string.h>

char st[205],ans[205];
int lenght;

int w(int i)
{
    if(i+2<lenght)
    {
        if(st[i]=='W' && st[i+1]=='U' && st[i+2]=='B')return 1;
    }
    return 0;
}
int main()
{

    int i,j;
    scanf("%s",st);
    lenght=strlen(st);
    for(i=0,j=0;i<lenght;)
    {
        if(w(i))
        {
            i+=3;
        }
        else
        {
            while(i<lenght && !w(i))
                ans[j++]=st[i++];
            ans[j++]=' ';
        }
    }
    ans[j++]='\n';
    printf("%s",ans);
    return 0;
}
