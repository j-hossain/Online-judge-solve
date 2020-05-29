#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[100005],t,n,i,cnt,mx,que;

    scanf("%d",&t);
    while(t--){


        scanf("%d",&n);

        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);

        cnt=1;
        que=0;
        for(i=0;i<n;i++){
            if(arr[i]<=cnt+que){
                cnt+=(que+1);
                que=0;
            }
            else
                que++;
        }

        printf("%d\n",cnt);
    }
    return 0;
}
