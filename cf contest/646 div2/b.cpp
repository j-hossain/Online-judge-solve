#include<stdio.h>
#include<string.h>
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

#define test        int t;scanf("%d",&t);while(t--)
#define inp(a,t)        scanf(t,&a);
#define inp2(a,b,t)     scanf(t t,&a,&b);
#define inp3(a,b,c,t)   scanf(t t t,&a,&b,&c);
#define inp4(a,b,c,d,t) scanf(t t t t,&a,&b,&c,&d);
#define out(a,t)        printf(t"\n",a);

#define ff(j,s,e,r)   for(j=s;j<e;j+=r)
#define bf(j,s,e,r)   for(j=s;j>e;j-=r)

#define DEC         int i,n,j,cnt=0,flag;

MM
{
    DEC
    char s[1005];
    int cumu[1005];
    int l,r,len,ans,a,b,temp;
    test
    {
        cnt=0;
        inp(s,st);
        len=strlen(s);
        cumu[0]=0;
        ff(i,0,len,1)
        {
            if(s[i]=='1')
                cnt++;
            cumu[i+1]=(s[i]-'0')+cumu[i];
        }
        if(cumu[len]==0)
        {
            printf("0\n");
            continue;
        }
        ans=len;
        ff(i,0,len,1)
        {
            j=i+1;
            if(s[i]=='1')
            {
                a=(j-cumu[j])+(cumu[len]-cumu[j]);
                b=((len-j)-(cumu[len]-cumu[j]))+cumu[j-1];
                temp=a<b?a:b;
                ans=ans<temp?ans:temp;
            }
        }
        ans=ans<cnt?ans:cnt;

        out(ans,it);
    }
    return 0;
}
