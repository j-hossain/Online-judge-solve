#include<stdio.h>
#include<math.h>

typedef struct
{
    int value;
    int cnt;
}point;

int main()
{
    int n,t,i,dif,mn,mx;
    point arr[100005],a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i].value);
            arr[i].cnt=0;
        }
        mx=0;
        for(i=1;i<n;i++)
        {
            if(arr[i].value<arr[i-1].value)
            {
                dif=arr[i-1].value-arr[i].value;
                a.cnt=log2(dif)+1;
                arr[i].value=arr[i-1].value;
                arr[i].cnt=a.cnt;
                if(arr[i].cnt>mx)
                    mx=arr[i].cnt;
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
