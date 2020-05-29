#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[105],pos[105],ans[100004],uni[105];
    int i,n,k,t,cnt,mx,j,x;
    scanf("%d",&t);
    while(t--)
    {


        scanf("%d %d",&n,&k);cnt=0;
        mx=k;
        for(i=0;i<105;i++)
            pos[i]=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(!pos[arr[i]])
            {
                pos[arr[i]]=1;
                uni[cnt++]=arr[i];
            }
            if(arr[i]>mx)
                mx=arr[i];
        }
        if(cnt<=k)
        {
            if(cnt<k)
            {
                i=1;
                while(i<=mx  && cnt<k)
                {
                    if(!pos[i])
                        uni[cnt++]=i;
                    i++;
                }
            }
            sort(&uni[0],&uni[cnt]);
            i=j=x=0;
            while(i<n)
            {
                ans[x]=uni[j];
                if(arr[i]==ans[x])
                    i++;
                x++;
                j++;
                if(j==cnt)
                    j=0;
            }
            printf("%d\n",x);
            for(i=0;i<x;i++)
                printf("%d ",ans[i]);
            printf("\n");
        }
        else
            printf("-1\n");
    }
    return 0;
}
