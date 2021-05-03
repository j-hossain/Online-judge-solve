#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
//accepted

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


DN
{
    fast();
    inout();
    
    li arr[100005],n,i,c,m,flag,minm,mxm,mxm2,flag1;

    test(){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1){
            flag=1;
        }
        if(n>1){
            c = arr[1]-arr[0];
            flag=flag1=1;
            for(i=2;i<n;i++){
                if(arr[i]-arr[i-1]!=c){
                    flag=0;
                    break;
                }
            }

            if(flag)
                goto printer;
            minm = 0;
            mxm = 0;
            for(i=1;i<n-1;i++){
                if(arr[i]>arr[mxm])
                    mxm = i;
                if(arr[i]<arr[minm])
                    minm = i;
            }
            if(arr[n-1]>mxm)
                mxm2 = arr[n-1];
            mxm2 = mxm;

            c = abs(arr[minm]-arr[minm+1]);
            m = arr[mxm]+c-arr[mxm+1];

            if(m<=arr[mxm2]){
                flag1 = 0;
                goto printer;
            }

            for(i=1;i<n;i++){
                if((arr[i-1]+c)%m!=arr[i]){
                    flag1=0;
                    break;
                }
            }
        }

        printer:

        if(flag){
            cout<<"0\n";
        }

        else if(!flag1){
            cout<<"-1\n";
        }
        else{
            cout<<m<<" "<<c<<"\n";
        }
    }
    return 0;
}
