#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<utility>
using namespace std;
///accepted

#define DN          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define mx          100005
#define spc         ' '
#define nn          "\n"

#define ff(s,e)         for(i=s;i<e;i++)
#define bf(s,e)         for(i=s;i>e;i--)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)


void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}
li arr[2005],dp[2005][2005];

li getAns(int x, int y){
    if(x==y)
        return 0;
    if(dp[x][y]!=-1)
        return dp[x][y];
    
    return dp[x][y] = min(getAns(x+1,y),getAns(x,y-1)) + arr[y]-arr[x];
} 


void solve(){
    li n,i,j,sum,mnSum;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            dp[i][j]=-1;

    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    mnSum = getAns(0,n-1);

    cout<<mnSum<<"\n";
    return;

}

DN
{
    // fast();
    inout();
    
    solve();

    return 0;
}
