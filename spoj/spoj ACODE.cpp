#include<stdio.h>
#include<string.h>
#define li long long int

li dp[5005][3];
char str[5005];

li run(int index, int take)
{
    if(str[index]=='\0')
        return 1;
    if(str[index]=='0')
        return 0;
    if(dp[index][take]!=-1)
        return dp[index][take];
    if(take==2)
    {
        if((str[index]>'2')||(str[index]=='2' && str[index+1]>'6') || str[index+1]=='\0')
            return 0;
    }
    dp[index][take]=(run(index+take,1)+run(index+take,2));
    return dp[index][take];
}

int main()
{
    li way;

    while(scanf("%s",str))
    {
        memset(dp,-1,sizeof(dp));
        if(!strcmp(str,"0"))
            break;

        way=(run(0,1)+run(0,2))/2;

        printf("%lld\n",way);
    }
    return 0;
}
