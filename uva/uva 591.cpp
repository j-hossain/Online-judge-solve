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

    int arr[55],n,sum,i,t=0;
    while(cin>>n)
    {
        t++;
        if(!n)
            break;

        sum=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }

        sum /= n;

        int cnt = 0;
        for(i=0;i<n;i++)
            if(arr[i]>sum)
            cnt+=(arr[i]-sum);

        cout<<"Set #"<<t<<endl;
        cout<<"The minimum number of moves is "<<cnt<<"."<<endl;
        cout<<endl;
    }



    return 0;
}
