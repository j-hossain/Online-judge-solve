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
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}


DN
{
    fast();
    inout();

    string a,b;
    int cnt, len, flag;

    test(){
        cnt = 0;

        cin>>a>>b;
        len = a.size();
        flag =0;
        for(int i=0; i<len; i+=2){
            if(a[i]!=b[i]){
                if(!flag){
                   flag =1;
                    cnt++;
                }
            }
            else
                flag = 0;
        }

        flag =0;
        for(int i=1; i<len; i+=2){
            if(a[i]!=b[i]){
                if(!flag){
                   flag =1;
                    cnt++;
                }
            }
            else
                flag = 0;
        }

        cout<<cnt<<endl;
    }

    return 0;
}
