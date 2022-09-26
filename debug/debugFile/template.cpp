/*   Bismillahir Rahmanir Rahim   */

#include<bits/stdc++.h>
using namespace std;
typedef   long long  int   ll;
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



int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

//    ll n;
//    cin>>n;
//    ll sum = 0;
//    while(n--)
//    {
//        ll num;
//        cin>>num;
//        sum = max(sum,num);
//    }
//
//    if(sum % 2 == 0) cout<<"Constantine"<<nn;
//    else cout<<"Mike\n";
    ll n;
    cin>>n;
    ll a[n+10],b[n+10],ans[n+10];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
    }
    priority_queue<pair<ll,pair<ll,ll>>>q;
    ll day=1;
    for(ll i=0; i<n; i++)
    {
        ll x=a[i];
        ll j=i+1;
        while(day<a[i]&&!q.empty())
        {
            if(day<q.top().second.second)
            day=q.top().second.second;
            ans[q.top().second.first]=day++;
            q.pop();
        }
        q.push({b[i]-a[i],{i,a[i]}});
        while(j<n&&x==a[j])
        {
            q.push({b[j]-a[j],{j,a[j]}});
            j++;
        }
        if(day<q.top().second.second)
            day=q.top().second.second;
        ans[q.top().second.first]=day++;
        q.pop();
        i=j-1;
    }
    while(!q.empty())
    {
        if(day<q.top().second.second)
            day=q.top().second.second;
        ans[q.top().second.first]=day++;
        q.pop();
    }
    for(ll i=0; i<n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;

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
