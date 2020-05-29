#include<stdio.h>

int pr(char a)
{
    if(a=='B')
        return 1;
    else if(a=='U')
        return 10;
    else if(a=='S')
        return 100;
    else if(a=='P')
        return 1000;
    else if(a=='F')
        return 10000;
    else if(a=='T')
        return 100000;
    else if(a=='M')
        return 1000000;
}

int check(int *ar,int t,int n)
{
    int i;

    for(i=1;i<n;i++)
    {
        if(t)
        {
            if(ar[i]<ar[i-1])
                return 0;
        }
        else
        {
            if(ar[i]>ar[i-1])
                return 0;
        }
    }
    return 1;
}

int main()
{
    //freopen("uvaOut.txt","w+",stdout);
    int arr[7],i,in,t,flag,ans,cnt;
    char inp[501];
    scanf("%d",&t);
    while(t--)
    {
        flag=1;
        for(i=0;i<7;i++)
        arr[i]=0;

        scanf("%s",inp);

        arr[0]+=pr(inp[0]);
        cnt=1;
        for(i=1,in=0;inp[i]!='\0';i++)
        {
            if(inp[i]!=inp[i-1])
            {
                in++;
                cnt=0;
                if(in==7)
                {
                    flag=0;
                    break;
                }
            }
            cnt++;
            arr[in]+=pr(inp[i]);
            if(cnt==10)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            if(check(arr,0,in+1)||check(arr,1,in+1))
            {
                ans=0;
                for(i=0;i<7;i++)
                    ans+=arr[i];
            }
            else
                flag=0;
        }

        if(flag)
            printf("%d\n",ans);
        else
            printf("error\n");
    }
    return 0;
}
