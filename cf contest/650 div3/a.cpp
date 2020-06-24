#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

#define MM          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(j,s,e,r)     for(j=s;j<e;j+=r)
#define bf(j,s,e,r)     for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}


MM
{
    fast();
    inout();
    char inp[105],out[105];
    int i,j,len;

    test()
    {
        cin>>inp;
        out[0]=inp[0];
        j=1;
        len=strlen(inp);
        for(i=1;i<len;i+=2,j++)
        {
            out[j]=inp[i];
        }
        out[j]='\0';
        cout<<out<<endl;
    }


    return 0;
}
