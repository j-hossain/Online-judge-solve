#include<stdio.h>
#define li  long long int
#define mx  200005

li arr[2*mx+1];
li dayC[2*mx+1],hugC[2*mx+1];

int main(){

    li m,mi,i,h,l,n,d;
    li ans,temp,check;

    scanf("%lld %lld",&n,&d);

    for(i=1;i<=n;i++){

        scanf("%lld",&arr[i]);
        arr[n+i]=arr[i];
    }

    dayC[0]=hugC[0]=arr[0]=0LL;

    for(i=1;i<=(2*n);i++){

        dayC[i]=dayC[i-1]+arr[i];
        hugC[i]=hugC[i-1]+(arr[i]*(arr[i]+1))/2;
    }

    i=2*n;
    ans=0LL;
    while(i>=n+1){

        l=1;
        h=mi=i;
        while(l<=h){

            m=(l+h)/2;

            if(dayC[i]-dayC[m]<=d){

                mi=m;
                h=m-1;
            }
            else
                l=m+1;
        }

        temp = (dayC[i]-dayC[mi-1])-d;
        check = hugC[i]-hugC[mi-1];
        check-=((temp*(temp+1))/2);

        if(check>ans)
            ans=check;
        i--;
    }

    printf("%lld\n",ans);
    return 0;
}
