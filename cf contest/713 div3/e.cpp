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

int mxPos(int till, int taken){
    return (taken*(2*till-taken+1))/2;
}

int mnPos(int x){
    return (x*(x+1))/2;
}


void solve(){
    int n,i,l,r,s,as,arr[505],brr[505],len;

    test(){
        cin>>n>>l>>r>>s;
        len=r-l+1;
        for(i=1;i<=n;i++)
            arr[i]=0;
        len = r-l+1;

        // cout<<as<<" "<<len<<"\n";
        for(i=n;i>=1;i--){
            if(s<=mxPos(i,len) && s-i>=mnPos(len-1)){
                s-=i;
                arr[i]=1;
                len--;
            }
        }

        // for(i=1;i<=n;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<"\n";
        // // cout<<s<<" "<<len<<"\n";
        if(s!=0 || len!=0){
            cout<<"-1\n";
            continue;
        }
        int x=1;
        int y=l;

        for(i=1;i<=n;i++){
            if(arr[i]){
                brr[y++] = i;
            }
            else{
                if(x==l)
                    x=r+1;
                brr[x++] = i;
            }
        }

        for(i=1;i<=n;i++){
            cout<<brr[i]<<" ";
        }
        cout<<"\n";

    }
}

DN
{
    // fast();
    inout();
    
    solve();

    return 0;
}
