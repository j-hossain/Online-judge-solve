#include<stdio.h>

int main(){

    int m,n,k,ans,mx,r,norm,toBe,t;

    scanf("%d",&t);
    while(t--){

        scanf("%d %d %d",&n,&m,&k);

        toBe = (n/k)*(k-1);

        norm = n-m;

        if(norm>=toBe){

            printf("%d\n",m);
            continue;
        }

        r = toBe - norm;
        mx=(r/(k-1));

        if(r%(k-1)!=0)
            mx++;

        r = n - toBe;

        printf("%d\n",r-mx);
    }
    return 0;
}
