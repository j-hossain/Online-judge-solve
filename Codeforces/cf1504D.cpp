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
    // freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

typedef struct{
    int i;  
    int j;
}node;

void solve(){
    vector<node> box[2];  
    node temp;
    int n,given,i,j,pos,chsn;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            temp.i = i;
            temp.j = j;
            box[(i+j)%2].push_back(temp);
        }
    }

    for(i=0;i<(n*n);i++){
        cin>>given;

        if(given==1){
            if(!box[1].empty()){
                pos = 1;
                chsn = 2;
            }else{
                pos = 0;
                chsn = 3;
            }
        }
        else if(given==2){
            if(!box[0].empty()){
                pos = 0;
                chsn = 1;
            }
            else{
                pos = 1;
                chsn = 3;
            }
        }
        else if(given==3){
            if(!box[0].empty()){
                pos = 0;
                chsn = 1;
            }
            else{
                pos = 1;
                chsn = 2;
            }
        }

        temp = box[pos].back();
        box[pos].pop_back();
        cout<<chsn<<" "<<temp.i<<" "<<temp.j<<"\n";
        cout.flush();
    }
}

DN
{
    // fast();
    // inout();
    
    solve();

    return 0;
}