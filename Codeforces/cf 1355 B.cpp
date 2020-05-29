#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    int ar[200005],i,n,cnt,mx,t,j;
    scanf("%d",&t);
    while(t--){
        cnt=0;
        scanf("%d",&n);

        for(i=0;i<n;i++){
           scanf("%d",&ar[i]);
        }

        sort(ar,ar+n);
        i=0,j=0,mx=0;
        while(i<n){
            if(ar[i]>mx)
                mx=ar[i];
            j++;
            if(j==mx)
            {
                cnt++;
                j=mx=0;
            }
            i++;
        }

        printf("%d\n",cnt);
    }
    return 0;
}
