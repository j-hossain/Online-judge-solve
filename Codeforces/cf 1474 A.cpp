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
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}


DN
{
    fast();
    inout();

    char a[100005],temp;
    int i,sum,n,prev;
    test(){
        cin>>n;
        cin>>a;
        sum=2;
        prev=-1;
        ff(0,n){
            if(a[i]=='0'){
                if(prev!=1){
                    cout<<"1";
                    prev=1;
                }
                else{
                    cout<<"0";
                    prev=0;
                }
            }
            else{
                if(prev!=2){
                    cout<<"1";
                    prev=2;
                }
                else{
                    cout<<"0";
                    prev=1;
                }
            }
        }
        cout<<nn;
    }
    return 0;
}
