#include<stdio.h>
#include<math.h>

int dif(int a,int b)
{
    return a>b?(a-b):(b-a);
}

int main()
{
    int m,i,n,l,h,x,arr[20];
    int lg,sum,mn,mx,way;

    scanf("%d %d %d %d",&n,&l,&h,&x);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    way=0;
    for(m=3;m<(1<<n);m++)
    {
        lg=log2(m);
        if(m==(1<<lg))
            continue;

        sum=mn=mx=0;

        for(i=0;i<n;i++)
        {
            if((1<<i)&m)
            {
                sum+=arr[i];

                if(!mn||mn>arr[i])
                    mn=arr[i];
                if(arr[i]>mx)
                    mx=arr[i];
            }
        }
        if(mx-mn>=x && l<=sum && sum<=h)
            way++;
    }

    printf("%d\n",way);
    return 0;
}
