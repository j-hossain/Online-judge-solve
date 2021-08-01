#include<iostream>
#include<string>
#include<cstring>
using namespace std;
//accepted
#define li long long int

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

li dp[65][65];
string inp;

li getIt(int st, int en){
    if(st>en)
        return 0;
    if(st==en)
        return dp[st][en]=1;
    if(dp[st][en]!=-1)
        return dp[st][en];

    // if(str[i] == str[j])
    //     return ret = (1 + rec(i+1, j-1)) + (rec(i+1, j) + rec(i, j-1) - rec(i+1, j-1));
    // else
    //     return ret = rec(i+1, j) + rec(i, j-1) - rec(i+1, j-1);

    if(inp[st]==inp[en])
        return dp[st][en] = 1+getIt(st+1,en)+getIt(st,en-1);
    else
        return dp[st][en]=getIt(st+1,en)+getIt(st,en-1)-getIt(st+1,en-1);
}

int main(){
    inout();
    li t,i,ans;
    cin>>t;
    for(int tk=1;tk<=t;tk++){
        cin>>inp;
        memset(dp,-1,sizeof(dp));
        ans = getIt(0,inp.size()-1);
        cout<<"Case "<<tk<<": "<<ans<<"\n";
    }
    return 0;
}