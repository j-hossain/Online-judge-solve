#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    long long a=1,b=0,c;
    char ar[100];
    scanf("%s",ar);
    int i,j,len;
    len=strlen(ar);
    for(i=1;i<=len-1;i++)
    {
        a*=10;
    }
    //printf("%d\n",a);
    for(j=0;j<len;j++)
    {
        b+=a*(ar[j]-'0');
        a/=10;
        //printf("%d ",b);
        //printf("%d ",a);
    }
    //printf("\n");
    printf("%lld\n",b);
}
