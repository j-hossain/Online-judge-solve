#include<iostream>
#include<string>
using namespace std;
#define li long long int 

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

string a,b;
int lcs[32][32],mnLen,aLen,bLen;
li ways[64][32][32];

int findLsc(){
    for(int i=0;i<=aLen;i++){
        for(int j=0;j<=bLen;j++){
            if(i==0 || j==0)
                lcs[i][j]=0;
            else if(a[i-1]==b[j-1]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else{
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }

    return lcs[aLen][bLen];
}

li findWays(int ml, int al, int bl){

    // cout<<ml<<" "<<al<<" "<<bl<<" "<<ways[ml][al][bl]<<"\n";
    if(ml==0){
        if(al==0 && bl==0)
            ways[ml][al][bl]=1;
        else
            ways[ml][al][bl]=0;   
    }

    if(ways[ml][al][bl]!=-1)
        return ways[ml][al][bl];

    else if(a[al-1]==b[bl-1])
        ways[ml][al][bl] = findWays(ml-1,al-1,bl-1);

    else if(al>0 && bl>0)
        ways[ml][al][bl] = findWays(ml-1,al-1,bl)+findWays(ml-1,al,bl-1);
    
    else if(al>0)
        ways[ml][al][bl] = findWays(ml-1,al-1,bl);
    
    else if(bl>0)
        ways[ml][al][bl] = findWays(ml-1,al,bl-1);
    
    return ways[ml][al][bl];    
}

int main(){
    inout();
    int t,tk=0;
    cin>>t;
    while(t--){
        tk++;
        cin>>a>>b;
        cout<<"Case "<<tk<<": ";
        // cout<<a<<" "<<b<<"\n";
        aLen = a.size();
        bLen = b.size();
        mnLen = findLsc();
        mnLen = aLen+bLen-mnLen;

        for(int k=0;k<=mnLen;k++){
            for(int i=0;i<=aLen;i++){
                for(int j=0;j<=bLen;j++){
                    ways[k][i][j]=-1;
                }
            }
        }

        li ans = findWays(mnLen,aLen,bLen);
        cout<<mnLen<<" "<<ans<<"\n";


    }    
}