#include<stdio.h>
#define mx 200005
#define test() printf("working\n");

int mnm(int a,int b)
{
    return a>b?b:a;
}

int mxm(int a,int b)
{
    return a<b?b:a;
}

int init(int *a)
{
    for(int i=0;i<3;i++)
            a[i]=-1;
}

int check(int *a)
{
    for(int i=0;i<3;i++)
            if(a[i]==-1)
                return 0;
    return 1;
}

int main()
{
    char arr[200005];
    int i,mapi[4],t,temp,j,k,p1,p2;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",arr);

        init(mapi);

        k=mx+10;
        for(i=0;arr[i]!='\0';i++)
        {
            temp=arr[i]-'1';
            mapi[temp]=i;
            if(check(mapi))
            {
                p1=mnm(mapi[0],mnm(mapi[1],mapi[2]));
                p2=mxm(mapi[0],mxm(mapi[1],mapi[2]));

                //printf("%d\n",p1);
                k=mnm(k,p2-p1+1);
            }

        }
        if(k==mx+10)
            printf("0\n");
        else
            printf("%d\n",k);
    }
    return 0;
}
