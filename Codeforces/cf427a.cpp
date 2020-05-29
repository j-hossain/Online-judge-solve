#include<stdio.h>
int main()
{
    long int n, a[100001],i,j,c=0,p=0;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
        scanf("%ld",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
        p+=a[i];
        else if(a[i]<0)
            p+=a[i];
        if(p<0)
        {
            c++;
            p=0;
        }
    }
    printf("%ld\n",c);
}
