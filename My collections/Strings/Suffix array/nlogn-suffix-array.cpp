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
#define t_start \
    auto start = high_resolution_clock::now();
#ifndef ONLINE_JUDGE
#define t_show                                                 \
    auto stop = high_resolution_clock::now();                  \
    auto duration = duration_cast<microseconds>(stop - start); \
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
#else
#define t_show
#endif
// </for runtime show>

//<for debug config>
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
template <typename _er>
void _print(_er t)
{
    cerr << t;
}
//</for debug config>

//<shortcut macros>
#define li \
    long long int
#define uli \
    unsigned long long int

// loops
#define ff(i, e) \
    for (int i = 0; i < e; i++)
#define bf(i, s) \
    for (int i = s - 1; i >= 0; i--)
#define ff2(j, s, e) \
    for (int j = s; j < e; j++)
#define bf2(j, s, e) \
    for (int j = s - 1; j >= e; j--)

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
#define pno \
    cout << "NO\n"
#define pys \
    cout << "YES\n"
#define out(x) \
    cout << x << " "
#define outln(x) \
    cout << x << "\n"
#define out2(x, y) \
    cout << x << " " << y << "\n"
#define pcs \
    cout << "Case " << TK << ": "
#define SS \
    ' '
#define NN \
    "\n"

// inputs simplified
#define ar_in(arr, n)  \
    ff(i, n)           \
    {                  \
        cin >> arr[i]; \
    }
// most used numbers
#define MM (int)(1e5)
#define MD (int)(1e9 + 7)
#define PI acos(0)
// template declarations simplified
#define vcc(x) vector<x>
#define qq(x) queue<x>
#define MP(a, b) make_pair(a, b)
//</shortcut macros>

// for segmentation
#define left st, (st + en) / 2, nd * 2
#define right (st + en) / 2 + 1, en, nd * 2 + 1

// ordered set
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// custom tuple class
class mtup
{
    int i;
    int v;
    mtup(int a, int b)
    {
        i = a;
        v = b;
    }
    bool operator<(const mtup &a) const
    {
        return v < a.v;
    }
    bool operator>(const mtup &a) const
    {
        return v > a.v;
    }
};
// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

// <Suffix array blackbox>
char str[MM];

int s0[(MM / 3) + 10], sa0[(MM / 3) + 10];
int n, ar[MM], sa[MM], lcp[MM], bucket[MM], mem[MM << 2];

void radixsort(int *source, int *dest, int *val, int n, int lim)
{
    int s = 0, x;
    memset(bucket, 0, lim << 2);
    ff(i, n)
        bucket[val[source[i]]]++;

    ff(i, lim)
    {
        x = bucket[i];
        bucket[i] = s, s += x;
    }
    ff(i, n)
        dest[bucket[val[source[i]]]++] = source[i];
}

void DC3(int *ar, int *sa, int n, int lim, int ptr)
{
    int *s12, *sa12;
    int allc = (n / 3) << 1, n0 = (n + 2) / 3;
    int i, j, k, l, c, d, p, t, m, r, counter;
    s12 = &mem[ptr], ptr += (allc + 5), sa12 = &mem[ptr], ptr += (allc + 5);

    c = 0, m = 0, r = n + ((n % 3) == 1);
    for (i = 0; i < r; i++, m++)
    {
        if (m == 3)
            m = 0;
        if (m)
            s12[c++] = i;
    }
    s12[c] = sa12[c] = s12[c + 1] = sa12[c + 1] = s12[c + 2] = sa12[c + 2] = 0;
    radixsort(s12, sa12, ar + 2, c, lim + 1);
    radixsort(sa12, s12, ar + 1, c, lim + 1);
    radixsort(s12, sa12, ar, c, lim + 1);

    counter = 0, j = -1;
    for (i = 0; i < c; i++)
    {
        if ((ar[sa12[i]] != j) || (ar[sa12[i] + 1] != k) || (ar[sa12[i] + 2] != l))
        {
            counter++;
            j = ar[sa12[i]], k = ar[sa12[i] + 1], l = ar[sa12[i] + 2];
        }
        if ((sa12[i] % 3) == 1)
            s12[sa12[i] / 3] = counter;
        else
            s12[(sa12[i] / 3) + n0] = counter;
    }

    if (counter == c)
    {
        for (i = 0; i < c; i++)
            sa12[s12[i] - 1] = i;
    }
    else
    {
        DC3(s12, sa12, c, counter, ptr);
        for (i = 0; i < c; i++)
            s12[sa12[i]] = i + 1;
    }

    for (i = 0, d = 0; i < c; i++)
    {
        if (sa12[i] < n0)
            s0[d++] = (sa12[i] * 3);
    }
    radixsort(s0, sa0, ar, d, lim + 1);
    for (k = 0, l = ((n % 3) == 1), r = 0; r < n; r++)
    {
        j = sa0[k];
        i = ((sa12[l] < n0) ? (sa12[l] * 3) + 1 : ((sa12[l] - n0) * 3) + 2);
        if (l == c)
            sa[r] = sa0[k++];
        else if (k == d)
            sa[r] = i, l++;
        else
        {
            if (sa12[l] < n0)
            {
                if ((ar[i] < ar[j]) || (ar[i] == ar[j] && s12[sa12[l] + n0] <= s12[j / 3]))
                    sa[r] = i, l++;
                else
                    sa[r] = j, k++;
            }
            else
            {
                if ((ar[i] < ar[j]) || (ar[i] == ar[j] && ar[i + 1] < ar[j + 1]) || (ar[i] == ar[j] && ar[i + 1] == ar[j + 1] && s12[sa12[l] - n0 + 1] <= s12[(j / 3) + n0]))
                    sa[r] = i, l++;
                else
                    sa[r] = j, k++;
            }
        }
    }
}

void LcpArray()
{
    int i, j, k;
    for (i = 0; i < n; i++)
        ar[sa[i]] = i;
    for (k = 0, i = 0; i < n; i++, k ? k-- : 0)
    {
        if (ar[i] == (n - 1))
            k = 0;
        else
        {
            j = sa[ar[i] + 1];
            while (((i + k) < n) && ((j + k) < n) && (str[i + k] == str[j + k]))
                k++;
        }
        lcp[ar[i]] = k;
    }
}

void genSuffixArray()
{
    int i, j, lim = 0;
    for (i = 0; i < n; i++)
    {
        ar[i] = str[i];
        if (ar[i] > lim)
            lim = ar[i];
    }

    ar[n] = ar[n + 1] = ar[n + 2] = 0;
    DC3(ar, sa, n, lim, 0);
}

// </Suffix array blackbox>

void answer()
{
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
    inout();
    t_start;
    // answer();
    test()
    {
        // pcs;
        answer();
    }
    t_show;

    return 0;
}
