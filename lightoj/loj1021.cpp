#include<iostream>
#include<string>
using namespace std;
//accepted
#define li unsigned long long int
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

li dp[(1<<17)][21];

int getDigit(char x){
    if('0'<=x && x<='9')
        return int(x-'0');
    else
        return int(x-'A')+10;
}

int main(){
    inout();
    li t,b,k,i,msk,r,len,d;
    string inp;
    

    cin>>t;
    for(int tk=1;tk<=t;tk++){
        cin>>b>>k;
        cin>>inp;
        len = inp.length();
        for(i=0;i<(1<<17);i++){
            for(int j=0;j<21;j++)
                dp[i][j]=0;
        }

        dp[0][0]=1;

        for(msk = 0; msk<(1<<len);msk++){
            for(i=0;i<len;i++){
                if(msk&(1<<i))
                    continue;
                for(r=0;r<k;r++){
                    d = getDigit(inp[i]);
                    dp[msk|(1<<i)][(r*b+d)%k]+=dp[msk][r];
                }
            }
        }
        cout<<"Case "<<tk<<": ";
        cout<<dp[(1<<len)-1][0]<<"\n";
    }
    return 0;
}