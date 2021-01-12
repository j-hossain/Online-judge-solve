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

#define ff(s,e)         for(li i=s;i<e;i++)
#define bf(s,e)         for(li i=s;i>e;i--)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)


void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}

int check(li n){
    li temp,num=n;
    while(num>0){
        temp = num%10;
        num/=10;
        if(!temp)
            continue;
        if(n%temp!=0)
            return 0;
    }
    return 1;
}

DN
{
    fast();
    inout();

    li n,ans;
    test(){
        cin>>n;
        ans=-1;
        ff(n,n+10000){
            if(check(i)){
                ans=i;
                break;
            }
        }

        cout<<ans<<nn;
    }

    return 0;
}
