#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MM          int main()
#define li          long long int
#define test        int t;scanf("%d",&t);while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(j,s,e,r)     for(j=s;j<e;j+=r)
#define bf(j,s,e,r)     for(j=s;j>e;j-=r)


MM
{
    li a,b,cnt,ans;
    test
    {
        cnt=ans=0LL;
        cin>>a>>b;
        if(a<b)
        {
            while(a<b)
            {
                a*=2;
                cnt++;
            }
        }
        else if(a>b)
        {
            while(a>b && a%2==0)
            {
                a/=2;
                cnt++;
            }
        }
        //cout<<a<<"--"<<b<<endl;
        if(a==b)
        {
            ans+=(cnt/3);
            cnt%=3;
            ans+=(cnt/2)+(cnt%2);
        }
        else
            ans=-1;

        cout<<ans<<endl;
    }
    return 0;
}

