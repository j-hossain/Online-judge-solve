#include<stdio.h>
#include<string.h>

int main()
{
    int sum,i,n,amount;
    char operation[7];
    sum=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",operation);
        if(!strcmp(operation,"donate"))
        {
            scanf("%d",&amount);
            sum+=amount;
        }
        else
            printf("%d\n",sum);
    }
    return 0;
}
