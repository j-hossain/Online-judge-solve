#include<stdio.h>
int main()
{
    int n,i,arr[101],a,cnt;

    scanf("%d %d",&n,&a);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    a--;
    if(arr[a])
        cnt=1;
    else
        cnt=0;

    for(i=1;i<n;i++)
    {
        if(a-i>=0 && a+i<n)
        {
            //printf("%d\n",i);
            if(arr[a-i] && arr[a+i])
                cnt+=2;
        }
        else if(a-i>=0)
        {
            if(arr[a-i])
                cnt++;
        }
        else if(a+i<n)
        {
            if(arr[a+i])
                cnt++;
        }
    }
    printf("%d\n",cnt);
}
