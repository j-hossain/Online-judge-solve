#include<stdio.h>

void inline inout()
{
    #ifndef ONLINE_JUDGE 
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int main(){
    
    inout();

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
