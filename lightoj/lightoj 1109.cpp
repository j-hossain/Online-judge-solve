#include<stdio.h>

typedef struct{
    int val;
    int cnt;
}num;

int main()
{
    int n,i,j;
    num mapi[1001],temp;

    for(i=1;i<1001;i++)
    {
        mapi[i].val = i;
        mapi[i].cnt=1;
    }

    for(i=2;i<=1001;i++)
    {
        for(j=i;j<1001;j+=i)
        {
            mapi[j].cnt++;
        }
    }


    for(i=1;i<1001;i++)
    {
        for(j=i;j<1001;j++)
        {
            if((mapi[i].cnt>mapi[j].cnt)||(mapi[i].cnt==mapi[j].cnt && mapi[i].val<mapi[j].val))
            {
                temp = mapi[i];
                mapi[i] = mapi[j];
                mapi[j] = temp;
            }
        }
    }

    int t,tk=0;
    scanf("%d",&t);
    while(t--)
    {
        tk++;
        scanf("%d",&n);
        printf("Case %d: %d\n",tk,mapi[n].val);
    }

    return 0;
}
