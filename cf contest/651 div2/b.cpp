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

    int n,num,even[2005],odd[2005],e,o;

    test()
    {
        cin>>n;
        e=o=0;
        for(int i=0;i<2*n;i++)
        {
            cin>>num;
            if(num%2)
                odd[o++]=i+1;
            else
                even[e++]=i+1;
        }
        if(o%2)
        {
            o--;
            e--;
        }
        else
        {
            if(e>o)
                e-=2;
            else
                o-=2;
        }

        for(int i=0;i<e;i+=2)
        {
            cout<<even[i]<<" "<<even[i+1]<<endl;
        }

        for(int i=0;i<o;i+=2)
        {
            cout<<odd[i]<<" "<<odd[i+1]<<endl;
        }
    }


    return 0;
}
