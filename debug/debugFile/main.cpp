// look for answer function for solution

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
#define t_show auto stop = high_resolution_clock::now();auto duration = duration_cast<milliseconds>(stop - start);cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
#else
#define t_show
#endif
// </for runtime show>

//<shortcut macros>
#define li  long long int
#define uli unsigned long long int

// most used numbers
const int MM = 1e5 + 3;
const int MD = 1e9 + 7;
const double PI = acos(0);
#define ll long long
//direction array
int dx[]= {-1, 1, 0, 0, -1,-1, 1, 1};
int dy[]= { 0, 0,-1, 1, -1, 1, -1, 1};

// runs test cases
#define test() int TT;cin >> TT;for (int TK = 1; TK <= TT; TK++)

// for faster cin cout
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// outputs simplified
#define pcs cout << "Case " << TK << ": "
#define SS  ' '
#define NN  '\n'

// template declarations simplified
#define pair<int,int>   pii
#define pair<li,li>     pll
#define MP(a, b)        make_pair(a, b)
#define PP(x)           push_back(x)
#define ALL(x)          x.begin(), x.end()

// for segmentation
#define left    st, (st + en) / 2, nd * 2
#define right   (st + en) / 2 + 1, en, nd * 2 + 1
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
    int n;
    cin>>n;
    int arr[n+2];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=1; i<n; i++)
    {
        arr[i]+=arr[i-1];
    }
    cout<<"Hello\n";
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check the if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    fast();
   ll t;
   cin>>t;
   while(t--)
   {
         ll n;
         cin>>n;
    string s;
    cin>>s;
    map<char,ll>mp;
     for(ll i=0;i<s.size();i++)
     {
      mp[s[i]]++;
     }
     ll gc=0;
     for(auto x:mp)
     {
         gc=__gcd(gc,x.second);
     }
//     if(gc==1)
//     {
//         cout<<"0\n";
//         continue;
//     }
     ll ans=0;
     for(auto x:mp)
     {
         ans+=x.second/gc;
     }



        cout<<n-ans<<"\n";
   }



    return 0;
}
