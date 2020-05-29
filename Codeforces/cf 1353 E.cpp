#include<stdio.h>
#define mx 1000005
char st[mx];
int arr[mx],i,n,k,cnt,c1,c2,t;
int dj[mx];

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n,&k);
        scanf("%s",st);

        arr[0]=st[0]-'0';
        for(i=1;i<n;i++)
            arr[i]=arr[i-1]+st[i]-'0';

        for(i=n-1;i>=0;i--){

            c1=(st[i]-'0')^1;
            if(i+k-1<n)
                c1+=(arr[i+k-1]-arr[i]);
            else
                c1+=(arr[n-1]-arr[i]);
            if(i+k<n)
                c1+=dj[i+k];

            c2 = arr[n-1]-arr[i]+st[i]-'0';

            dj[i]= c1<c2?c1:c2;
        }

        cnt=dj[0];

        for(i=1;i<n;i++){

            dj[i]+=arr[i-1];
            cnt=cnt<dj[i]?cnt:dj[i];
        }

        printf("%d\n",cnt);
    }
    return 0;
}
