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


DN
{
    fast();

    int n,temp,cnt,sec,tk=0,total;

    test()
    {
        tk++;
        temp=cnt=sec=total=0;
        cin>>n;
        while(sec<n)
        {
            temp++;
            sec++;
            total++;
            cnt++;
            if(temp==3)
            {
                cnt--;
                total--;
            }
            if(cnt==47)
            {
                sec+=42;
                cnt=0;
            }
            if(temp==5)
                temp=0;
        }

        cout<<"Case "<<tk<<": "<<total<<endl;
    }



    return 0;
}
