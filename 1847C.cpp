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

// C++ program for a Trie based O(n) solution to find max
// subarray XOR
#include<bits/stdc++.h>
using namespace std;

// Assumed int size
#define trnLen 9

// A Trie Node
struct trn
{
	int v;
	trn *arr[2];
};

trn *newNode()
{
	trn *temp = new trn;
	temp->v = 0;
	temp->arr[0] = temp->arr[1] = NULL;
	return temp;
}

void addNum(trn *root, int pre)
{
	trn *temp = root;

	for (int i=trnLen-1; i>=0; i--)
	{
		bool val = pre & (1<<i);

		if (temp->arr[val] == NULL)
			temp->arr[val] = newNode();

		temp = temp->arr[val];
	}

	temp->v = pre;
}

int getAns(trn *root, int pre)
{
	trn *temp = root;
	for (int i=trnLen-1; i>=0; i--)
	{
		bool val = pre & (1<<i);
        
		if (temp->arr[1-val]!=NULL)
			temp = temp->arr[1-val];

		else if (temp->arr[val] != NULL)
			temp = temp->arr[val];
	}
	return pre^(temp->v);
}



void precalc(){
    
}

void answer(){
    int n;
    cin>>n;
    int a[n+2];
    for(int i=0;i<n;i++) cin>>a[i];
    trn *cur = newNode();
	addNum(cur, 0);

	int ans = INT_MIN, pre =0;

	for (int i=0; i<n; i++)
	{
		pre = pre^a[i];
		addNum(cur, pre);

		ans = max(ans, getAns(cur, pre));
	}
	cout<<ans<<NN;
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