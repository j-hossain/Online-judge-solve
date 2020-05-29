#include<stdio.h>

int main()
{
    int arr[100002],n,i,j,in1,in2,flag,mx;

    mx=0;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>mx)
            mx=arr[i];
    }

    arr[0]=0;
    arr[n+1]=mx+1;
    in1=in2=0;
    flag=0;

    for(i=1;i<=n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            in1=i-1;
            while(arr[i]>=arr[i+1] && i<=n)
            {
                i++;
            }
            in2=i;
            if(arr[in2]>arr[in1-1] && arr[in1]<arr[in2+1])
            {
                i=in2;
                flag++;
            }
            else
                break;
        }
    }
    if(in1==0 && in2==0)
    {
        printf("yes\n");
        printf("1 1\n");
    }
    else if(flag==1)
    {
        printf("yes\n");
        printf("%d %d\n",in1,in2);
    }
    else
        printf("no\n");
    return 0;
}
