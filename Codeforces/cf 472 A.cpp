#include<stdio.h>
int main()
{
    int n;
    int n1,n2;
        scanf("%d",&n);
        if(n%2)
        {
            n1=n-9;
            n2=9;
        }
        else
        {
            n1=n-4;
            n2=4;
        }
    printf("%d %d\n",n1,n2);
    return 0;
}
