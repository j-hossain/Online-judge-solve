#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
#define li long long int
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

li mem[33][3][3],lf[33][3][3],num[33],dig;

li getIt(int pos, int pol, int sam){
    // cout<<"from: "<<pos<<" "<<pol<<" "<<sam<<" "<<dig<<'\n';
    if(pos==dig){
        lf[pos][pol][sam]=1;
        return 0;
    }
    if(mem[pos][pol][sam]!=-1){
        return mem[pos][pol][sam];
    }

    if(sam){
        int nxt = num[pos];
        if(nxt){
            mem[pos][pol][sam] = getIt(pos+1,1,1)+getIt(pos+1,0,0);
            lf[pos][pol][sam] = lf[pos+1][1][1]+lf[pos+1][0][0];
            if(pol==1){
                mem[pos][pol][sam]+=lf[pos+1][1][1];
            }
        }
        else{
            mem[pos][pol][sam] = getIt(pos+1,0,1);
            lf[pos][pol][sam] = lf[pos+1][0][1];
        }
    }
    else{
        mem[pos][pol][sam] = getIt(pos+1,1,0)+getIt(pos+1,0,0);
        lf[pos][pol][sam] = lf[pos+1][1][0]+lf[pos+1][0][0];
        if(pol==1){
            mem[pos][pol][sam]+=lf[pos+1][1][0];
        }
    }
    return mem[pos][pol][sam];
}


int main(){
    inout();
    int t;
    li n, ans,h;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        memset(mem,-1,sizeof mem);
        memset(lf,0,sizeof lf);
        cin>>n;
        if(n==0)
            h=0;
        else
            h = log2(n);
        num[0]=0;
        int j=1;
        for(int i=h;i>=0;i--){
            if((1<<i)&n)
                num[j++] =1;
            else
                num[j++] = 0;
        }
        dig=j;

        ans = getIt(0,0,1);
        cout<<"Case "<<tt<<": "<<ans<<"\n";
    }
}