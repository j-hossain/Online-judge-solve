#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define DN          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;

#define ff(s,e)         for(i=s;i<e;i+=r)
#define bf(s,e)         for(i=s;i>e;i-=r)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}


int i,n,k,nums[200005],ww[200005],f,r,j,mx[200005],mn[200005];

DN
{
    fast();
    inout();

    long long int sum;

    test()
    {
        cin>>n>>k;
        sum=0;
        for(i=0;i<n;i++)
        {
            cin>>nums[i];

        }

        for(i=0;i<k;i++)
        {
            mn[i]=10e9+10;
            mx[i]=-mn[i];
            cin>>ww[i];
        }


        sort(ww,ww+k);
        sort(nums,nums+n);

        i=n-1;
           for(j=0;j<k;j++)
           {
               if(ww[j])
               {
                   mx[j]=nums[i];
                   mn[j]=nums[i];
                   i--;
                   ww[j]--;
               }
           }

           for(j=0;j<k;j++)
           {
               while(ww[j])
               {
                   mn[j]=nums[i];
                   i--;
                   ww[j]--;
               }
           }

        for(i=0;i<k;i++)
        {
            sum+=(mx[i]+mn[i]);
        }

        cout<<sum<<endl;
    }



    return 0;
}
