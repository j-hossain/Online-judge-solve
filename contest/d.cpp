#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}
int dif(int a, int b)
{
    return a>b?(a-b):(b-a);
}

DN
{
    fast();

    char inp[15];
    int i,num,mn,ni,d;
    ni=753;

    cin>>inp;
    mn=-1;
    int len = strlen(inp);
    for(i=0;i<len-2;i++)
    {
        num=((inp[i]-'0')*100+(inp[i+1]-'0')*10+(inp[i+2]-'0'));
        d=dif(num,ni);
        if(d<mn || mn==-1)
        {
            mn=d;
        }
    }

    cout<<mn<<endl;


    return 0;
}
