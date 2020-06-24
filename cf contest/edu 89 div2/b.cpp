#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define MM          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(j,s,e,r)     for(j=s;j<e;j+=r)
#define bf(j,s,e,r)     for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}


MM
{
    fast();
    inout();

    int n,m,ans,mxx,mn,x,a,b;
    test()
    {
        cin>>n>>x>>m;
        mn=mxx=x;
        while(m--)
        {
            cin>>a>>b;

            if(a>b)
            {
                a=a+b;
                b=a-b;
                a=a-b;
            }
            if(a<=mn && b>=mxx)
            {
                mn=a;
                mxx=b;
            }
            else if(a<=mn && mn<=b)
                mn=a;
            else if(a<=mxx && mxx<=b)
                mxx=b;

            //cout<<mxx<<" "<<mn<<endl;
        }

        ans=mxx-mn+1;
        cout<<ans<<endl;
    }


    return 0;
}
