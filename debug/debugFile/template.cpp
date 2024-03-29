/*   Bismillahir Rahmanir Rahim   */

#include<bits/stdc++.h>
using namespace std;
typedef    int   ll;
typedef      long long  ld;
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



int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;

    ll a[n],b[n];
    for(ll i = 0; i < n; i++) cin>>a[i]>>b[i];

    vector<float>v;
    v.pb(0);
    v.pb(0.1);
    v.pb(0.2);
    v.pb(0.3);
    v.pb(0.4);
    v.pb(0.5);
    v.pb(0.6);
    v.pb(0.7);
    v.pb(0.8);
    v.pb(0.9);
    v.pb(0.01);
    v.pb(0.02);
    v.pb(0.03);
    v.pb(0.04);
    v.pb(0.05);
    v.pb(0.06);
    v.pb(0.07);
    v.pb(0.08);
    v.pb(0.09);
    v.pb(1.0);

    for(float i = 10; i <= 200; i++)
    {
        float dnum = i/100.0;
        v.pb(dnum);

    }

    ll f = 0;

    for(float x : v)
    {
        float y = 1.0 - x;

        vector<float>v1;
        for(ll i = 0; i < n; i++)
        {
            float rat1 = float(max(a[i],b[i]));
            float rat2 = float(min(a[i],b[i]));

            float t = x * rat1 + y * rat2;
            v1.pb(t);
           // cout<<t<<ss;
        }

        ll d = 1;

        for(ll i = 1; i < n; i++)
        {
            if(v1[i] > v1[i-1]) d = 0;
        }
       // cout<<nn;

        if(d) f = 1;

    }



    if(f) cout<<"YES\n";
    else cout<<"NO\n";



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
