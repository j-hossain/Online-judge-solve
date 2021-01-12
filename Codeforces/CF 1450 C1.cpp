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
    char grid[615][615];
    int i,j,n,cnt,mnCnt,mnS,s,k;

        for(i=0;i<615;i++){
            for(j=0;j<615;j++)
                grid[i][j]='0';
        }

    test(){
        cin>>n;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                cin>>grid[i][j];
            }
        }
        if(n>=3){
            mnCnt=-1;
            for(s=1;s<=3;s++){
                cnt=0;
                for(i=s;i<=2*n;i+=3){
                    for(j=i,k=1;j>0 && k<=n;j--,k++){
                        if(grid[k][j]=='X')
                            cnt++;
                    }
                }
                if(mnCnt==-1 || cnt<mnCnt){
                    mnCnt = cnt;
                    mnS = s;
                }
            }
            for(i=mnS;i<=2*n;i+=3){
                for(j=i,k=1;j>0 && k<=n;j--,k++){
                    if(grid[k][j]=='X')
                        grid[k][j]='O';
                }
            }

        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                cout<<grid[i][j];
            }
            cout<<nn;
        }
    }
    return 0;
}
