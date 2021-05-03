#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
#define li long long int

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

li maxIf[18][1<<17];
li inp[18][18],n;

li getMax(int row, int colsTaken){
    li mxR = -1;
    if(row>n){
        return 0;
    }
    if(maxIf[row][colsTaken]!=-1){
        return maxIf[row][colsTaken];
    }
    for(int i=1;i<=n;i++){
        int bt = 1<<(i-1);//jehetu 1<<, mane aagei 1 ache tai i-1 korte hocche 
        if(!(colsTaken&bt)){
            mxR = max(mxR, inp[row][i] + getMax(row+1,colsTaken|bt));
        }
    }
    maxIf[row][colsTaken]=mxR;
    return mxR;
}

int main(){
    inout();
    int i,j,t,tc;
    cin>>t;
    for(tc=1;tc<=t;tc++){
        cin>>n;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                cin>>inp[i][j];
                maxIf[i][j]=inp[i][j];
            }
        }

        for(i=0;i<=n;i++){
            for(j=0;j<=(1<<n);j++)
                maxIf[i][j]=-1;
        }
        li ans = getMax(1,0);
        cout<<"Case "<<tc<<": ";
        cout<<ans<<"\n";
    }

    return 0;
}