#include<stdio.h>

typedef struct
{
    int cnt;
    char c;
}ch;

int main()
{
    char st[4];
    ch ar[3],temp;
    int i,n;

    ar[0].cnt=ar[1].cnt=ar[2].cnt=0;

    for(i=0;i<3;i++)
    {
        scanf("%s",st);
        if(st[1]=='>')
        {
            ar[st[0]-'A'].cnt++;
            ar[st[2]-'A'].cnt--;
            ar[st[0]-'A'].c=st[0];
            ar[st[2]-'A'].c=st[2];
        }
        else if(st[1]=='<')
        {
            ar[st[0]-'A'].cnt--;
            ar[st[2]-'A'].cnt++;
            ar[st[0]-'A'].c=st[0];
            ar[st[2]-'A'].c=st[2];
        }
    }

    if(ar[0].cnt!=ar[1].cnt && ar[1].cnt!=ar[2].cnt && ar[0].cnt!=ar[2].cnt )
    {
        if(ar[0].cnt>ar[1].cnt)
        {
            temp=ar[0];
            ar[0]=ar[1];
            ar[1]=temp;
        }
        if(ar[0].cnt>ar[2].cnt)
        {
            temp=ar[0];
            ar[0]=ar[2];
            ar[2]=temp;
        }
        if(ar[1].cnt>ar[2].cnt)
        {
            temp=ar[1];
            ar[1]=ar[2];
            ar[2]=temp;
        }
        printf("%c%c%c\n",ar[0].c,ar[1].c,ar[2].c);
    }
    else
        printf("Impossible\n");
    return 0;
}
