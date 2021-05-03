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
//accepted

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

int grph[102][102];

int check(int i,int j,int n,int col){
    int x[] = {-1,0,1,0};
    int y[] = {0,1,0,-1};

    if(grph[i][j]!=0)
        return 0;

    for(int d=0;d<4;d++){
        int tempx = i+x[d];
        int tempy = j+y[d];

        if(tempx>=0 && tempy>=0 && tempx<n && tempy<n){
            if(grph[tempx][tempy]==col){
                return 0;
            }
        }
    }
    return 1;
}

void pagoleKinaKore(){
    int v1,v2,n,i,cnt[2];
    string inp,a,b;

    test(){
        cin>>n;
        cin>>inp;
        v1=v2=cnt[0]=cnt[1]=0;
        a.clear();
        b.clear();
        for(i=0;i<n;i++){
            cnt[inp[i]-'0']++;
        }

        if(cnt[0]%2!=0 || inp[0]!='1' || inp[n-1]!='1'){
            cout<<"NO\n";
            continue;
        }
        for(i=0;i<n;i++){
            if(inp[i]=='1'){
                if(v1<(cnt[1]/2)){
                    a.push_back('(');
                    b.push_back('(');
                }
                else{
                    a.push_back(')');
                    b.push_back(')');
                }
                v1++;
            }
            else{
                if(v2==0){
                    a.push_back('(');
                    b.push_back(')');
                }
                else{
                    a.push_back(')');
                    b.push_back('(');
                }
                v2^=1;
            }
        }

        cout<<"YES\n";
        cout<<a<<"\n"<<b<<"\n";
    }
    return;
}

DN
{
    fast();
    inout();
    
    pagoleKinaKore();

    return 0;
}
