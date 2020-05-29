#include<stdio.h>
#include<string.h>
int main()
{
    int tk,lenght,i;
    int flag1,flag0;
    char s[1005];
    scanf("%d",&tk);
    while(tk--)
    {
        flag0=flag1=0;

        scanf("%s",s);
        lenght=strlen(s);
        for(i=0;i<lenght;i++)
        {
            if(s[i]=='0')
                flag0=1;
            else
                flag1=1;
        }
        if(flag0 && flag1)
        {
            for(i=0;i<lenght*2;i++)
            {
                if(i%2)
                    printf("0");
                else
                    printf("1");
            }
            printf("\n");
        }
        else
            printf("%s\n");
    }
    return 0;
}
