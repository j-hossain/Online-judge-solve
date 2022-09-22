/*   Bismillahir Rahmanir Rahim   */

#include<bits/stdc++.h>
using namespace std;
typedef    long long    ll;
typedef      long double   ld;
typedef     vector<ll>      vll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define     fi              first
#define     se              second
#define     pb              push_back
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define     nn              "\n"
#define     all(p)          p.begin(),p.end()
#define     zz(v)           (ll)v.size()
#define     ss              ' '
#define     pii            pair<ll,ll>
#define     gcd(a,b)        __gcd(a,b)
#define     lcm(a,b)        (a*b)/gcd(a,b)

const ll N = 1e9 + 7;
const ll mxn=1010;
ll vi[mxn+10];
ll colure[mxn+10];
vector<ll>g[mxn+10];

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,k,u,v;
    cin>>n>>m>>k;
    for(ll i=0; i<m; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);

    }
    for(ll i=1; i<=n; i++)
    {
        colure[i]=-1;
    }
//    for(ll i=1; i<=n; i++)
//    {
//        cout<<colure[i]<<" ";
//    }
//    cout<<endl;
    ll f=0;
    for(ll i=1; i<=n; i++)
    {
        if(colure[i]!=-1)continue;
        set<ll>st1,st2;
        for(auto v:g[i])
        {
            st1.insert(v);
            st2.insert(colure[v]);
        }
        ll c=1;
        while(1)
        {
            if(st2.find(c)==st2.end())
                break;
            c++;
        }
        colure[i]=c;

        for(ll j=1; j<=n; j++)
        {
            if(st1.find(j)==st1.end())
            {
                if(colure[j]==-1)
                {
                    colure[j]=c;
                }
                else if(colure[j]!=c)
                    f=1;
            }
        }
//        for(ll j=1;j<=n;j++)
//            cout<<colure[j]<<" ";
//        cout<<endl;
    }
    for(ll i=1; i<=n; i++)
    {
        for(auto v:g[i])
        {
            if(colure[i]==colure[v])
            {
                f=1;
                break;
            }
        }
    }
    for(ll i=1; i<=n; i++)
    {
        if(colure[i]>k)
        {
            f=1;
            break;
        }
    }
    if(f)cout<<"-1"<<endl;
    else
    {
        for(ll i=1; i<=n; i++)
            cout<<colure[i]<<" ";
        cout<<endl;
    }


    return 0;

    /* you should actually read the stuff at the bottom  */

}

/*

    * do something instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/


/* Final check before submit :

1. array size or integer overflow,like uninitialised 0 index.

2. Think twice,code once.check all possible counter test case.

3. Be careful about corner case! n=1?k=1? something about 0?

4. avoid stupid mistake!complexity(t/m)?precision error?submit same code twice?

5. if got WA than remember that you are missing something common.
   *** Be confident!!! who knows? may be your one step back to AC ***
4. minus mod ans=(ans-k+mod)%mod;



*/


/* IF WA???

1. corner case! n=1?k=1? something about 0?

2. check code(avoid stupid mistake)

3. read the statement again(if there any missing point???)

4. check the idea(check all possible counter test case again!!!)

5. be calm,don't be panic!!!.(***this problem not going to decide your future***)

6. don't waste too much time. move to next problem

*/
