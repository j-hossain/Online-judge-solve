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

void changeGrid(char grid[][615], char from, char to, int s, int n){
    for(int i=s;i<=2*n;i+=3){
        for(int j=i,k=1;j>0 && k<=n;j--,k++){
            if(grid[k][j]==from)
                grid[k][j]=to;
        }
    }
}

void findOut(char grid[][615],int *c1, int *c2, int mxp, int n){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(i==j)
                continue;
            if(c1[i]+c2[j]<=mxp){
                changeGrid(grid,'O','X',j,n);
                changeGrid(grid,'X','O',i,n);
                return;
            }
        }
    }
}

DN
{
    fast();
    inout();
    char grid[615][615],a,b;
    int s,c1[4],c2[4],mxp;
    int i,j,n,k,xc,oc;


    test(){
        for(i=0;i<615;i++){
            for(j=0;j<615;j++)
                grid[i][j]='0';
        }
        cin>>n;
        xc=oc=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                cin>>grid[i][j];
                if(grid[i][j]=='X')
                    xc++;
                else if(grid[i][j]=='O')
                    oc++;
            }
        }
        if(n>=3){
            mxp = (xc+oc)/3;
            for(s=1;s<=3;s++){
                c1[s]=c2[s]=0;
                for(i=s;i<=2*n;i+=3){
                    for(j=i,k=1;j>0 && k<=n;j--,k++){
                        if(grid[k][j]=='X')
                            c1[s]++;
                        else if(grid[k][j]=='O')
                            c2[s]++;
                    }
                }
            }

            findOut(grid,c1,c2,mxp,n);

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
