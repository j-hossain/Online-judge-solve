#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define DN          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(s,e)         for(i=s;i<e;i+=r)
#define bf(s,e)         for(i=s;i>e;i-=r)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("G:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}


DN
{
    fast();
    inout();
    int n,pr,no,m,mi,i,arr[300005];
    test(){
        mi = -1;
        m = 0;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>m)
                m = arr[i];
        }
        for(i=0;i<n;i++){
            if(arr[i]==m && i<n-1){
                if(arr[i]>arr[i+1]){
                    mi = i+1;
                    break;
                }
            }
            if(arr[i]==m && i>0){
                if(arr[i]>arr[i-1]){
                    mi = i+1;
                    break;
                }
            }
        }

        cout<<mi<<endl;
    }
    return 0;
}
