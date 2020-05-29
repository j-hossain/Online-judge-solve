#include<stdio.h>
#include<string.h>

int main()
{
    int lenght,mid,i,flag;
    char st[1000005],temp[1000005];
    int t;

    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%s",st);
        strcpy(temp,st);
        lenght=strlen(st)-1;
        mid=lenght/2;

        for(i=0;i<=mid;i++)
        {
            temp[lenght-i]=temp[i];
        }

        if(strcmp(temp,st)>0)
        {
            printf("%s\n",temp);
            continue;
        }

        for(i=mid;i>=0;i--)
        {
            if(temp[i]!='9')
            {
                temp[i]++;
                temp[lenght-i]=temp[i];
                break;
            }
            temp[i]=temp[lenght-i]='0';
        }
        if(temp[0]=='0')
        {
            temp[0]=temp[++lenght]='1';
            temp[++lenght]='\0';

        }
        printf("%s\n",temp);
    }
    return 0;
}
