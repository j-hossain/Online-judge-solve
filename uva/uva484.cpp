#include<stdio.h>

int sz,num,i,mapi[200005],arr[200005];

int main()
{
    i=0;
    while(scanf("%d",&num)!=EOF)
    {
        if(mapi[num]==0)
            arr[i++]=num;
        mapi[num]++;
    }
    sz=i;

    for(i=0;i<sz;i++)
        printf("%d %d\n",arr[i],mapi[arr[i]]);

    return 0;
}
