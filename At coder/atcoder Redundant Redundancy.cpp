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

#define mx          100005
#define spc         ' '
#define nn          "\n"

#define ff(s,e)         for(i=s;i<e;i++)
#define bf(s,e)         for(i=s;i>e;i--)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)


void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}

li gcd(li a, li b)
{
    if (b != 0)
       return gcd(b, a % b);
    else
       return a;
}

li lcm(li a, li b){
    return (a*b)/gcd(a,b);
}

DN
{
    fast();
    //inout();

    li n,ans,i;
    cin>>n;
    ans = 1LL;
    ff(2,n+1)
    {
        ans = lcm(i,ans);
    }
    ans++;
    cout<<ans<<nn;

    return 0;
}
