//Not accepted


#include<stdio.h>

int arr[4000005],i,n,t,m1,m2,mn,temp;

int dif(int a, int b)
{
    return a>b?(a-b):(b-a);
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        m1=((n+1)/2)+1;
        m2=(n/2)+1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            arr[n+i]=arr[2*n+i]=arr[i];

        }

        for(i=1;i<3*n;i++)
        {
            arr[i]+=arr[i-1];
        }
        mn=-1;
        for(i=n;i<2*n;i++)
        {
            temp = dif(arr[i],arr[i+m1])+dif(arr[i],arr[i-m2]);
            if(temp<mn || mn==-1)
                mn=temp;
        }

        printf("%d\n",mn);
    }
    return 0;
}
