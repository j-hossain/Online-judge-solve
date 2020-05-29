#include<stdio.h>
#include<string.h>

int main()
{
    int num1[255],num2[255],add[10000];
    char st1[255],st2[255];
    int mul,mr,ar,sum;
    int l1,l2,la;
    int i,j,a;

    while(scanf("%s %s",st1,st2)!=EOF)
    {
        for(i=0;i<10000;i++)
            add[i]=0;

        l1=strlen(st1);
        l2=strlen(st2);

        for(i=l1;i>0;i--)
            num1[l1-i]=st1[i-1]-'0';
        for(i=l2;i>0;i--)
            num2[l2-i]=st2[i-1]-'0';

        la=0;
        for(i=0;i<l1;i++)
        {
            ar=mr=0;
            a=i;
            for(j=0;j<l2;j++)
            {
                mul=num1[i]*num2[j]+mr;
                mr=mul/10;
                mul%=10;
                add[a]+=(mul+ar);
                ar=add[a]/10;
                add[a]%=10;
                a++;

            }
            if(mr || ar)
            {
                ar+=mr;
                while(ar>0)
                {
                    add[a]+=ar;
                    ar=add[a]/10;
                    add[a]%=10;
                    a++;
                }
            }
            if(a>la)
                la=a;
        }
        sum=0;
        for(i=0;i<la;i++)
            sum+=add[i];
        if(!sum)
        {
            printf("0\n");
            continue;
        }
        for(i=la-1;i>=0;i--)
            printf("%d",add[i]);
        printf("\n");
    }
    return 0;
}
