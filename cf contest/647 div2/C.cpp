#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MM          int main()
#define li          long long int
#define test        int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(j,s,e,r)     for(j=s;j<e;j+=r)
#define bf(j,s,e,r)     for(j=s;j>e;j-=r)

int logi(li n)
{
    if(n==1)return 0;
    return 1+logi(n/2);
}

MM
{
    fast();
    li n,ans;
    li mn,x,temp,tt;
    test{
        cin>>n;
        if(n==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        ans=0LL;
        tt=0LL;
        mn=n;
        while(tt<n)
        {
            x=logi(mn);
            mn=pow(2,x);
            temp=pow(2,x+1)-1;
            ans+=temp;
            tt+=mn;
            mn=n-tt;
        }
            cout<<ans<<endl;
    }
    return 0;
}

