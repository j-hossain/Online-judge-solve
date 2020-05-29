#include<stdio.h>
#include<string.h>

int main()
{
    char number[100001];
    int num,i,lenght,sum,cnt;
    scanf("%s",number);
    lenght=strlen(number);

    sum=0;
    cnt=0;
    for(i=0;i<lenght;i++)
    {
        num=number[i]-'0';
        sum+=num;
    }

    if(lenght>1)
        cnt=1;
    num=sum;
    while((num/10)>=1)
    {
        cnt++;
        sum=0;
        while(num>0)
        {
            sum+=(num%10);
            num/=10;
        }
        num=sum;
    }
    printf("%d\n",cnt);
    return 0;
}
