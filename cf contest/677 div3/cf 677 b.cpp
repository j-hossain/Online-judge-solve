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
    //inout();

    int n,l,r;
    int arr[55];
    test(){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];

        for(int i=0; i<n; i++){
            if(arr[i]){
                i++;
                while(arr[i])
                    i++;
                l = i-1;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(arr[i]){
                i--;
                while(arr[i])
                    i--;
                r = i+1;
                break;
            }
        }
        int cnt = 0;
        if(l!=r){
            for(int i=l; i<r; i++){
                if(!arr[i])
                    cnt++;
            }
        }

        cout<<cnt<<endl;
    }
    return 0;
}
