#include<stdio.h>

int main()
{
    int a,b,c,d,n,t,h1,h2,l1,l2,flag;
    double test;
    int mid;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d",&n);
        scanf("%d %d",&a,&b);
        scanf("%d %d",&c,&d);
        h1=c+d;
        l1=c-d;
        h2=a+b;
        l2=a-b;

        //mid=(h1+l1)/2;
        while(h1>=l1)
        {
            mid=(h1+l1)/2;
            test=(double)mid/n;
            //printf("%f\n",test);
            if(test<=h2 && test>=l2)
            {
               flag=1;
               break;
            }
            else if(test>h2)
                h1=mid-1;
            else if(test<l2)
                l1=mid+1;
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
