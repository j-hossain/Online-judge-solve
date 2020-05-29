#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long int arr[100005],arr2[100005],ans;
    int i,n,l,r,t,ins;

    arr[0]=arr2[0]=0;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
        arr2[i]=arr[i];
        arr[i]+=arr[i-1];
    }

    sort(arr2+1,arr2+n+1);
    for(i=1;i<=n;i++)
        arr2[i]+=arr2[i-1];


    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&ins,&l,&r);

        if(ins==1)
            ans=arr[r]-arr[l-1];

        else
            ans=arr2[r]-arr2[l-1];

        printf("%lld\n",ans);
    }
    return 0;
}
