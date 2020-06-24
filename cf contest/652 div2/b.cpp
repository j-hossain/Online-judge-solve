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

    int n,fo,lz,i;
    char inp[200005];

    test()
    {
        lz=-1;
        fo=-1;
        cin>>n;
        cin>>inp;
        for(i=0;i<n;i++)
        {
            if(inp[i]=='1')
            {
                fo=i;
                break;
            }
        }
        for(i=fo;i<n;i++)
        {
            if(inp[i]=='0')
                lz=i;
        }
        if(fo==-1 || lz==-1)
            cout<<inp<<endl;
        else
        {
            for(i=0;i<fo;i++)
                cout<<inp[i];
            for(i=lz;i<n;i++)
                cout<<inp[i];
            cout<<endl;
        }
    }


    return 0;
}
