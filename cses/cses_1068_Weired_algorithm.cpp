#include<stdio.h>
//accepted
int main(){
    long long int n;
    scanf("%lld",&n);
    printf("%lld ",n);
    while(n!=1){
        if(n&1)
            n = 3*n+1;
        else
            n/=2;
        printf("%lld ",n);
    }
    return 0;
}