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

#define mx          100005
#define spc         ' '
#define nn          "\n"

#define ff(s,e)         for(i=s;i<e;i+=1)
#define bf(s,e)         for(i=s;i>e;i-=1)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}


DN
{
    fast();
    inout();

    int n,x,arr[505],arr2[505],i,cnt,st,flag;

    test(){
        cin>>n>>x;
        flag=1;
        ff(0,n){
            cin>>arr[i];
        }
        ff(1,n){
            if(arr[i]<arr[i-1]){
                flag=0;
                break;
            }

        }
        if(flag){
           cout<<0<<nn;
           continue;
        }
        st=-1;
        cnt=0;
        ff(0,n-1){
            if(arr[i]>arr[i+1]){
                st=i;
            }
        }

        i=0;
        while(i<=st){
            if(arr[i]>x){
                cnt++;
                swap(arr[i],x);
            }

            i++;
        }
        ff(1,n){
            if(arr[i]<arr[i-1]){
                cnt=-1;
                break;
            }

        }

        cout<<cnt<<nn;
    }

    return 0;
}
