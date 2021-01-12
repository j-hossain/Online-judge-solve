#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

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
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}


DN
{
    fast();
    inout();

    char grid[1000][1000];

    int n,m,r,c,tc,tr;

    cin>>n>>m;

    for(i=0;i<n;i++)
        cin>>grid[i];
    r=c=0;
    flag=1;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(grid[i][j]=='*'){
                r++;
                tc=i;
                break;
            }
        }
        if(i>1)
            break;
    }

    print:
        if(flag){
            if(r2==-1)
        }


    return 0;
}
