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

int bigger(li a, li b){
    return a>b;
}

    li n,arr[200005],a,b,temp,tr,i;

DN
{
    fast();
    inout();

    test(){
        cin>>n;
        a=b=0;
        ff(0,n){
            cin>>arr[i];
        }

        tr=1;

        sort(arr,arr+n,bigger);

        for(i=0;i<n;i++){
            if(tr==1){
                if(arr[i]%2==0)
                    a+=arr[i];
                tr=tr^1;
            }
            else {
                if(arr[i]%2){
                    b+=arr[i];
                }
                tr=tr^1;
            }
        }

        //cout<<a<<spc<<b<<nn;

        if(a>b)
            cout<<"Alice\n";

        else if(a<b)
            cout<<"Bob\n";

        else
            cout<<"Tie\n";

    }



    return 0;
}
