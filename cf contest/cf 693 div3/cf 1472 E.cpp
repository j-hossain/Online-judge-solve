#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
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
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}

typedef struct st{
    int h;
    int w;
    int pos;
}pr;

int comp(pr a, pr b){
    if((a.h<=b.h && a.w<=b.w)||(a.h<=b.w && a.w<=b.h)){
        return 1;
    }
    return 0;
}

pr arr[200005];

DN
{
    fast();
    inout();
    int n,i,mapi[200005],w,h;


    test(){
        cin>>n;
        ff(0,n){
            cin>>arr[i].h>>arr[i].w;
            arr[i].pos=i;
            mapi[i]=-1;
        }

        sort(arr,arr+n,comp);

//        ff(0,n)
//            cout<<arr[i].h<<spc<<arr[i].w<<spc<<arr[i].pos<<nn;
//        cout<<nn;

        w=arr[0].w;
        h=arr[0].h;
        ff(1,n){
            if((arr[i].h>h && arr[i].w>w)||(arr[i].h>w && arr[i].w>h))
                mapi[arr[i].pos] = arr[0].pos+1;
        }

        ff(0,n)
        cout<<mapi[i]<<spc;
        cout<<nn;
    }


    return 0;
}
