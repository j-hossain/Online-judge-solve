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
#define mx          100005

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


DN
{
    fast();
    inout();

    li arr[200005],i,n,cnt,mxr,num,k,j;

    test()
    {
        cin>>n>>k;
        mxr=0;
        j=0;
        for(i=0;i<n;i++)
        {
            cin>>num;
            if(num%k)
                arr[j++]=k-(num%k);

            mxr = mxr>arr[j-1]?mxr:arr[j-1];
        }

        sort(arr,arr+j);


        i=1;
        while(i<j)
        {
            mxr=mxr>arr[i]?mxr:arr[i];

            cnt=0;
            while(arr[i]==arr[i-1] && i<j)
            {
                num=(cnt+1)*k+arr[i];
                mxr = mxr>num?mxr:num;
                cnt++;
                i++;
            }

                i++;
        }
        if(mxr)
            mxr++;
        cout<<mxr<<endl;
    }


    return 0;
}
