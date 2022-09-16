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
void inline inout(){
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

li arr[505][505],brr[505][505];
li pa[505][505],pb[505][505];
li uptil[505][505];
li rmx[505],valc[505];
li n,m;

void answer(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>brr[i][j];
		}
	}
	for(int j=0;j<m;j++){
		pa[0][j] = arr[0][j];
		for(int i=1;i<n;i++){
			pa[i][j] = pa[i-1][j]+arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=m-2;j>=0;j--){
			pa[i][j] += pa[i][j+1];
		}
	}
	for(int j=0;j<m;j++){
		pb[0][j] = brr[0][j];
		for(int i=1;i<n;i++){
			pb[i][j] = pb[i-1][j]+brr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=m-2;j>=0;j--){
			pb[i][j] += pb[i][j+1];
		}
	}

	li ans = pa[n-1][0];
	for(int i=0;i<n;i++) rmx[i]=-1;
	for(int j=m-1;j>=0;j--){
		if(pa[n-1][0]-pa[n-1][j]+pb[n-1][j]>=ans){
			rmx[n-1]=j;
			ans = pa[n-1][0]-pa[n-1][j]+pb[n-1][j];
			valc[j] = pa[n-1][j]-pb[n-1][j];
			continue;
		}
		li lc = rmx[n-1];
		li lr = n-1;
		li rad=0;
		li urn=0;
		for(int i=n-2;i>=0;i--){
			// li temp_rad=0;
			// li temp_urn=0;
			if(lc==-1){
				rad = pb[i][j];
				urn = pa[i][j];
			}
			else{
				rad = pb[i][j]-pb[i][lc];
				urn = pa[i][j]-pa[i][lc];
			}
			if(pa[n-1][0]-rad+urn+valc[lc]>=ans){
				rmx[i]=j;
				ans = pa[n-1][0]-rad+urn+valc[lc];
				valc[j] = valc[lc]+pa[n-1][j]-pb[n-1][j];
				break;
			}
		}
	}
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check the if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main(){
    fast();
    inout();
//    t_start;
//     for no test case
//     answer();

//     when test cases exist
    test(){
//         pcs;
        answer();
    }
//     t_show;

    return 0;
}
