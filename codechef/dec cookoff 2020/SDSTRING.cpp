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


char inp[1000005];

DN
{
    fast();
    inout();
    int c1,c2,len,i;
    test(){
        cin>>inp;
        c1=c2=0;
        for(i=0;inp[i]!='\0';i++){
            if(inp[i]=='1')
                c1++;
            else
                c2++;
        }

        if(i%2 || c1==i || c2==i){
            cout<<"-1\n";
            continue;
        }

        len = abs(c2-c1);

        cout<<(len/2)<<nn;
    }

    return 0;
}
