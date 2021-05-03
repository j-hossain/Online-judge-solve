#include<stdio.h>
#define mod 10000007

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int a, b, c, d, e, f;
int fnvals[10004];

int fn(int n) {
    if(fnvals[n]!=-1)
        return fnvals[n];
    fnvals[n] =  ((fn(n-1)%mod) + (fn(n-2)%mod) + (fn(n-3)%mod) + (fn(n-4)%mod) + (fn(n-5)%mod) + (fn(n-6)%mod))%mod;
    return fnvals[n];  
}

int main() {
    inout();
    int n, cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        for(int i=0;i<10004;i++)
            fnvals[i]=-1;
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        fnvals[0]=a;
        fnvals[1]=b;
        fnvals[2]=c;
        fnvals[3]=d;
        fnvals[4]=e;
        fnvals[5]=f;
        printf("Case %d: %d\n", caseno, fn(n) % mod);
    }
    return 0;
}