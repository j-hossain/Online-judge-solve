#include<iostream>
#include<string>
using namespace std;
#define mx 200005
int matchMap[6][mx];
string combs[6];

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}


void generateCombs(int len){
    combs[0].append("abc");
    combs[1].append("acb");
    combs[2].append("bac");
    combs[3].append("bca");
    combs[4].append("cab");
    combs[5].append("cba");
    for(int i=0;i<6;i++){
        for(int j=3;j<len;j++){
            combs[i].push_back(combs[i][j-3]);
        }
    }
}

int main(){
    inout();
    int t, len, n,l,r,ans;
    string inp;
    cin>>len>>n;
    generateCombs(len);
    cin>>inp;
    for(int i=0;i<6;i++){
        matchMap[i][0] = 0;
        for(int j=1;j<=len;j++){
            matchMap[i][j] = matchMap[i][j-1]+(combs[i][j-1]!=inp[j-1]);
        }
    }

    for(int i=0;i<n;i++){
        cin>>l>>r;
        ans = matchMap[0][r] - matchMap[0][l-1];
        for(int i=1;i<6;i++){
            ans = min(ans,matchMap[i][r] - matchMap[i][l-1]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}