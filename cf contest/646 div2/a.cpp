#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define st          "%s"
#define it          "%d"
#define dt          "%lf"
#define lit         "%lld"
#define MM          int main()
#define li          long long int

#define test         int t;scanf("%d",&t);while(t--)
#define inp(a,t)        scanf(t,&a);
#define inp2(a,b,t)     scanf(t t,&a,&b);
#define inp3(a,b,c,t)   scanf(t t t,&a,&b,&c);
#define inp4(a,b,c,d,t) scanf(t t t t,&a,&b,&c,&d);
#define out(a,t)        printf(t"\n",a);

#define ff(j,s,e,r)   for(j=s;j<e;j+=r)
#define bf(j,s,e,r)   for(j=s;j>e;j-=r)

#define DEC         int i,n,j,cnt=0,flag=0;

MM
{
    DEC
    int x,e,o,temp;
    test
    {
        flag=0;
        e=o=0;
        inp2(n,x,it);
        ff(i,0,n,1)
        {
            inp(temp,it);
            if(temp%2)
                o++;
            else
                e++;
        }
        if(o>0)
        {
                if(o>=x)
                    flag=1;
                else
                {
                    if(o%2 || e>x-o)
                        flag=1;
                }
            if(x%2==0)
            {
                if(flag && e==0)
                    flag=0;
            }

        }

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
