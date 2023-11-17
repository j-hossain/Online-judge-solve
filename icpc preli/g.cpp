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
#define SS " "
#define NN "\n"
#define pyes cout << "YES\n"
#define pno cout << "NO\n"

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
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

void precalc()
{
}

void answer()
{
    string s;
    cin >> s;
    int n = s.size();
    int r = 0;
    int w = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
            w++;
        else
        {
            r += (s[i] - '0');
        }
    }
    string ov = "Over";
    if ((double)n / 6 > 1)
        ov += "s";
    string rn = "Run";
    if (r > 1)
        rn += "s";
    string wk = "Wicket";
    if (w > 1)
        wk += "s";

    cout << n / 6 << "." << n % 6 << " " << ov << " " << r << " " << rn << " " << w << " " << wk << "." << NN;
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    fast();
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

0 0 0 0 0
1 1 1 0 0
2 2 2 0 0
3 3 3 0 0
4 4 4 0 0
5 5 5 0 0
6 6 0 6 6
7 0 1 7 1
8 1 2 8 1
9 2 3 9 1
10 3 4 10 1
11 4 5 11 1
12 5 0 16 5
13 6 1 21 5
14 0 2 23 2
15 1 3 25 2
16 2 4 27 2
17 3 5 29 2
18 4 0 33 4
19 5 1 37 4
20 6 2 41 4
21 0 3 44 3
22 1 4 47 3
23 2 5 50 3
24 3 0 53 3
25 4 1 56 3
26 5 2 59 3
27 6 3 62 3
28 0 4 66 4
29 1 5 70 4
30 2 0 72 2
31 3 1 74 2
32 4 2 76 2
33 5 3 78 2
34 6 4 80 2
35 0 5 85 5
36 1 0 86 1
37 2 1 87 1
38 3 2 88 1
39 4 3 89 1
40 5 4 90 1
41 6 5 91 1
42 0 0 91 0