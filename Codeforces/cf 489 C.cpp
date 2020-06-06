#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MM          int main()
#define ll          long long int
#define test        int t;scanf("%d",&t);while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(j,s,e,r)     for(j=s;j<e;j+=r)
#define bf(j,s,e,r)     for(j=s;j>e;j-=r)


MM
{
    DEC;
    int s,ts,m;
    char sm[105],bg[105];
    fast();
    cin>>n>>s;
    if((!s && n>1) || 9*n<s)
    {
        cout<<"-1 -1"<<endl;
        return 0;
    }
    if(n==1)
    {
        cout<<s<<" "<<s<<endl;
        return 0;
    }
    ts=s;
    ff(i,1,n+1,1)
    {
        bf(j,9,-1,1)
        {
            if(ts-j>=0)
            {
                bg[i-1]=j+'0';
                ts-=j;
                break;
            }
        }
    }
    ts=0;
    ff(i,1,n+1,1)
    {
        if(bg[n-1]=='0' && i==1)
        {
            ts=1;
            sm[0]='1';
            continue;
        }

        if(bg[n-i]!='0' && ts)
        {
            sm[i-1]=bg[n-i]-1;
            ts=0;
            continue;
        }

        sm[i-1]=bg[n-i];
    }
    sm[n]=bg[n]='\0';
    cout<<sm<<" "<<bg<<endl;
    return 0;
}
