// including all header files
#include <bits/stdc++.h>

//<for policy based data structure>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//</for policy based data structure>

using namespace std;

// <for runtime show>
using namespace std::chrono;

#define t_start auto start = high_resolution_clock::now();
#ifndef ONLINE_JUDGE
#define t_show                                                 \
    auto stop = high_resolution_clock::now();                  \
    auto duration = duration_cast<milliseconds>(stop - start); \
    cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
#else
#define t_show
#endif
// </for runtime show>

//<shortcut macros>
#define ll long long int
#define uli unsigned long long int

// most used numbers
const int MM = 2e5 + 3;
const int MD = 1e9 + 7;
const double PI = acos(0);

// direction array
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

// runs test cases
#define test() \
    int TT;    \
    cin >> TT; \
    for (int TK = 1; TK <= TT; TK++)

// for faster cin cout
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// outputs simplified
#define pcs cout << "Case " << TK << ": "
#define SS ' '
#define NN '\n'

// template declarations simplified
#define pii pair<int, int>
#define pll pair<li, li>
#define MP(a, b) make_pair(a, b)
#define PP(x) push_back(x)
#define ALL(x) x.begin(), x.end()

// for segmentation
#define left st, (st + en) / 2, nd * 2
#define right (st + en) / 2 + 1, en, nd * 2 + 1
#define pb push_back
//</shortcut macros>

// ordered set
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

void answer()
{
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check the if the value can be 0
//  -> check
//if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

const ll mxn=1e6+10;
ll isp[mxn+10];
vector<ll>prime;

ll pa[mxn+10];
ll pp[mxn+10];

void siv()
{
    for(ll i=4; i<=mxn; i+=2)isp[i]=1;
    for(ll i=3; i*i<=mxn; i+=2)
    {
        if(isp[i]==0)
        {
            for(ll j=(i*i); j<=mxn; j+=(i+i))
                isp[j]=1;
        }
    }
    prime.pb(2);
    pp[2] = -1;
    for(ll i=3; i<=mxn; i+=2)
    {
        if(isp[i]==0){
            prime.pb(i);
            pp[i]=-1;
        }
    }
}
void make_set()
{
    for(ll i=0; i<=mxn; i++)
        pa[i]=i;
}

ll join(ll n)
{
    if(pa[n]==n)return n;
    else return pa[n]=join(pa[n]);
}

void unio(ll u,ll v)
{
    u=join(u);
    v=join(v);
    pa[v]=u;
}

map<ll,ll>mp;
void fact(ll n,ll Ind)
{
    for(ll i=0; prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            if(pp[prime[i]]==-1){
                pp[prime[i]]=Ind;
            }
            else{
                unio(pp[prime[i]],Ind);
            }
            while(n%prime[i]==0)
            {
                n/=prime[i];
            }
        }
    }
    if(n>1)
    {
        if(pp[n]==-1){
            pp[n]=Ind;
        }
        else
            unio(pp[n],Ind);
    }
}


// for faster cin cout
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main()
{
    fast();
    //siv();
    ll t;
    cin>>t;
    int tk=1;
    while(t--)
    {
        ll a[20];
        for(ll i=1;i<=15;i++)
    }



    return 0;
}


