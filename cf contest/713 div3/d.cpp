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


void solve(){

    li i,n,arr[200005],sum,x,y;

    test(){
        cin>>n;
        n+=2;
        sum=0LL;
        x=-1;
        for(i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        sort(arr,arr+n);
        y=n-1;
        sum-=arr[n-1];
        for(i=0;i<n-1;i++){
            if(sum-arr[i]==arr[n-1]){
                x=i;
                break;
            }
        }
        if(x==-1 && sum-arr[n-2]==arr[n-2]){
            x=n-1;
            y=n-2;
        }

        // cout<<x<<" "<<y<<"\n";
        if(x==-1){
            cout<<x<<"\n";
            continue;
        }

        for(i=0;i<n;i++){
            if(i!=x && i!=y)
                cout<<arr[i]<<" ";
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
