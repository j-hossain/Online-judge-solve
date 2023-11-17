// including all header files
#include <bits/stdc++.h>

//<for policy based data structure>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//</for policy based data structure>

using namespace std;

//<shortcut macros>
#define ll long long int
#define dll long double
#define ull unsigned long long int

// most used numbers
const ll MM = 1e6 + 3;
const ll MD = 1e9 + 7;
const double PI = acos(-1.0);

// direction array
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

// runs test cases
#define test() int TT;cin >> TT;for (int TK = 1; TK <= TT; TK++)

// for faster cin cout
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// outputs simplified
#define pcs cout << "Case " << TK << ": "
#define SS " " 
#define NN "\n"
#define pyes cout<<"YES\n"
#define pno cout<<"NO\n"

// template declarations simplified
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vll vector<ll>
#define pb push_back
#define All(x) x.begin(), x.end()

// for segmentation
#define left st, (st + en) / 2, nd * 2
#define right (st + en) / 2 + 1, en, nd * 2 + 1
//</shortcut macros>

// ordered set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

ll k;

struct TrieNode
{
    TrieNode *arr[2];
    int cnt;
};

TrieNode *root;
 
TrieNode *newNode()
{
    TrieNode *temp = new TrieNode;
    temp->cnt = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}
 
void insert(TrieNode *root, int num)
{
    TrieNode *temp = root;
 
    for (ll i=k-1; i>=0; i--)
    {
        bool val = num & (1LL<<i);
 
        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();
        temp->arr[val]->cnt++;
        temp = temp->arr[val];
    }
}

pair<ll,ll> getAns(TrieNode *u, int i, ll p){
    // cout<<i<<SS<<p<<NN;
    if(u==NULL) return {0LL,0LL};
    ll x = u->cnt<2?0LL:1LL;
    if(i==0) return {x,p};
    pll a = getAns(u->arr[0],i-1,0);
    pll b = getAns(u->arr[1],i-1,1);
    pll ret;
    ret.first = (x<<i)+max(a.first,b.first);
    ret.second = (p<<i)|(a.first>b.first?a.second:b.second);
    // cout<<ret.first<<SS<<ret.second<<SS<<i<<SS<<p<<NN;
    return ret;
}

void precalc(){
    
}

void answer(){
    ll n;
    cin>>n>>k;
    root = newNode();
    ll a[n+2];
    for(int i=0;i<n;i++){
        cin>>a[i];
        insert(root,a[i]);
    }
    pll tar = (max(getAns(root->arr[0],k-1,0),getAns(root->arr[1],k-1,1)));
    cout<<tar.first<<SS<<tar.second<<NN;
    ll ans = 0LL;
    ll a1,a2;
    a1 = a2= -1;
    for(int i=0;i<n;i++){
        if((a[i]&tar.second)==tar.second){
            if(a1==-1) a1 = i;
            else{
                a2 = i;
                break;
            }
        }
    }
    for(ll i = k-1;i>=0;i--){
        if((a[a1]<<i)==(a[a2]<<i)){
            ans|=((1<<i)^(a[a1]<<i));
        }
    }
    cout<<a1+1<<SS<<a2+1<<SS<<ans<<NN;
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    // fast();
    // inout();
    precalc();
    //     for no test case
    // answer();

    //     when test cases exist
    test()
    {
        // cout<<"Case "<<TK<<":"<<NN;
        // pcs;
        answer();
    }

    return 0;
}