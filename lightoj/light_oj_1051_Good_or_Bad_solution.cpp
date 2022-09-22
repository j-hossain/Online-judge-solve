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
#define pii             pair<int,int>
#define pll             pair<li,li>
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

int arr[55];
int mem[55][55][55];
int n;

int getAns(int p, int o, int z){
	if(p==n) return 0;
	// cout<<arr[p]<<"\n";
	if(mem[p][o][z]!=-1) return mem[p][o][z];
	int ret=0;
	int oo=0;
	int zz=0;
	if(arr[p]==-1){
		oo = getAns(p+1,o+1,0);
		zz = getAns(p+1,0,z+1);
		if(o+1>=3) oo=1;
		if(z+1>=5) zz=1;

		if(oo==0 and zz==0) ret = 0;
		else if(zz==2 or oo==2 or (zz==1 and oo==0) or (zz==0 and oo==1)){
			ret = 2;
			// cout<<p<<" "<<oo<<" "<<zz<<"\n";
		}
		else ret = 1;
	}
	else if(arr[p]){
		ret = getAns(p+1,o+1,0);
		if(o+1>=3) ret=1;
	}
	else{
		ret = getAns(p+1,0,z+1);
		if(z+1>=5) ret=1;
	}

	return mem[p][o][z] = ret;
}

void answer(){
	string str;
	cin>>str;
	int badf=0;
	int goodf=0;
	n = str.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				mem[i][j][k]=-1;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(str[i]=='A' or str[i]=='E' or str[i]=='I' or str[i]=='O' or str[i]=='U') arr[i]=1;
		else if(str[i]!='?') arr[i]=0;
		else arr[i]=-1;
	}

	int ans = getAns(0,0,0);
	if(ans==0){
		cout<<"GOOD\n";
	}
	else if(ans==1){
		cout<<"BAD\n";
	}
	else{
		cout<<"MIXED\n";
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
        pcs;
        answer();
    }
//     t_show;

    return 0;
}
