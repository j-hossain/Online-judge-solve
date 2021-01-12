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

li n,na[300005],ma[300005],m,i,j,sum;

DN
{
    fast();
    inout();


    test(){
        cin>>n>>m;
        ff(0,n)
            cin>>na[i];
        ff(0,m)
            cin>>ma[i];

        sort(na,na+n);

        j=sum=0;
        for(i=n-1;i>=0;i--){
            if(j<na[i]){
                sum+=ma[j];
                j++;
            }
            else
                sum+=ma[na[i]-1];

        }

        cout<<sum<<nn;
    }

    return 0;
}
