#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
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
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}


void solve(){

    char grid[405][405];
    int i,j,n,r[5],c[5];

    test(){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>grid[i];
        }
        int x=1;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]=='*'){
                    r[x]=i;
                    c[x]=j;
                    x++;
                }       
            }
        }

        if(r[1]==r[2]){
            if(r[1]<n-1){
                r[3]=r[4]=r[1]+1;
            }
            else{
                r[3]=r[4]=r[1]-1;
            }
            // cout<<r[3]<<"\n";
            c[3]=c[1];
            c[4]=c[2];
        }
        else if(c[1]==c[2]){
            if(c[1]<n-1){
                c[3]=c[4]=c[1]+1;
            }
            else{
                c[3]=c[4]=c[1]-1;
            }
            r[3]=r[1];
            r[4]=r[2];
        }
        else{
            r[3]=r[1];
            c[3]=c[2];
            r[4]=r[2];
            c[4]=c[1];
        }
        grid[r[3]][c[3]]='*';
        grid[r[4]][c[4]]='*';

        for(i=0;i<n;i++){
            cout<<grid[i]<<"\n";
        }   
        // cout<<"\n";
    }    
    
}

DN
{
    fast();
    inout();
    
    solve();

    return 0;
}
