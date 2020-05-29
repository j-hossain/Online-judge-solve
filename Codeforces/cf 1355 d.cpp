#include<stdio.h>

int main(){
    int s,n;
    scanf("%d %d",&n,&s);

    if(s>=2*n){
        printf("YES\n");
        while(n>1){
            printf("2 ");
            s-=2;
            n--;
        }
        if(s)
            printf("%d\n",s);
        printf("1\n");
    }
    else
        printf("NO\n");
    return 0;
}
