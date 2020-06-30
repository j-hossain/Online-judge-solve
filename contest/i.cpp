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
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

li fib[45];

void fibInit()
{
    fib[0]=0LL;
    fib[1]=1LL;

    for(int i=2;i<42;i++)
        fib[i]=fib[i-1]+fib[i-2];
}

li finder(int now, int dd)
{
    li cnt=0LL;
    if(now==dd)
        return fib[now+1];
    for(int i=0;i<=fib[now+1];i++)
        cnt +=finder(0,dd-1);
    cnt+=finder(now+1,dd);
    return cnt;
}

DN
{
    fast();

    li n,d;
    li cnt;
    fibInit();
    test()
    {
        cin>>n>>d;
        cnt = finder(0,d);
        cout<<cnt<<endl;
    }



    return 0;
}
