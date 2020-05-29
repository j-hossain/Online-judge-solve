#include<stdio.h>

int main(){

    int t,x1,x2,y1,y2;

    long long int ans;

    scanf("%d",&t);

    while(t--){

        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        ans=((long long int)x2-x1)*(y2-y1)+1;

        printf("%lld\n",ans);
    }
    return 0;
}
