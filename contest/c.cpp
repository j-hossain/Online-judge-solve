#include<stdio.h>

int main()
{
    int a,b,sum,s2;

    scanf("%d %d",&a,&b);
    sum=0;
    if(a%2)
    {
        printf("%d is odd\n",a);
        sum-=a;
    }
    else
    {
        printf("%d is even\n",a);
        sum+=a;
    }

    if(b>0)
    {
        printf("%d is greater than zero\n",b);
        sum+=b;
    }
    else if(b<0)
    {
        printf("%d is less than zero\n",b);
        sum-=b;
    }
    else if(b==0)
    {
        printf("%d is equal to zero\n",b);
        sum*=b;
    }

    s2=a+b;
    printf("after adding,a+b is equal to %d\n",s2);
    if(s2%2)
    {
        sum-=s2;
        printf("after removing %d %d sum is equal to %d\n",a,b,sum);
    }
    else
    {
        sum+=s2;
        printf("after adding %d %d sum is equal to %d\n",a,b,sum);
    }

    if(s2==0)
    {
        sum*=10;
        printf("the result after multiplying sum = %d\n",sum);
    }
    sum*=5;
    printf("THE ULTIMATE RESULT = %d\n",sum);
    printf("I wanna be a national contestant and I can write long code\n");
    return 0;
}























