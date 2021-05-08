#include<iostream>
#include<string>
#define li long long int
//accepted

using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

string st;
li t,n,frd[1000005],bkd[1000005],cnt;

int main(){
    inout();
    cin>>t;
    while(t--){
        cin>>n>>st;
        cnt=(st[0]=='*');
        frd[0]=0;
        for(int i=1;i<n;i++){
            frd[i] = st[i]=='*'?frd[i-1]:frd[i-1]+cnt;
            cnt+=(st[i]=='*');
        }
        bkd[n-1]=0;
        cnt=(st[n-1]=='*');
        for(int i=n-2;i>=0;i--){
            bkd[i] = st[i]=='*'?bkd[i+1]:bkd[i+1]+cnt;
            cnt+=(st[i]=='*');
        }

        cnt = -1;
        for(int i=0;i<n-1;i++){
            if(frd[i]+bkd[i+1]<cnt || cnt==-1)
                cnt = frd[i]+bkd[i+1];
        }
        if(cnt==-1)
            cnt=0;
        cout<<cnt<<"\n";

    }
}