#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main()
{
    char strng[21];
    int sum,sq,i;
    while(scanf("%s",strng)!=EOF)
    {
        sum=0;
        for(i=0;strng[i]!='\0';i++)
        {
            if(isupper(strng[i]))
                sum+=((strng[i]-'A')+27);
            else
                sum+=(strng[i]-'a'+1);
        }
        sq=sqrt(sum);
        for(i=2;i<=sq;i++)
        {
            if(!(sum%i))
                break;
        }
        //printf("%d %d\n",sum,sq);
        if(i>sq || sum==2)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}
