#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
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

    int n,i,e,o;
    int num,cnte,cnto;

    test()
    {
        cin>>n;
        cnte=cnto=0;
        e=o=0;
        for(i=0;i<n;i++)
        {
            cin>>num;
            if(num%2)
            {
                if(!(i%2))
                    cnte++;
            }
            else
            {
                if(i%2)
                    cnto++;
            }
        }
        if(!cnte && !cnto)
        {
            cout<<"0"<<endl;
            continue;
        }
        if(cnte==cnto)
            cout<<cnte<<endl;
        else
            cout<<"-1"<<endl;

    }


    return 0;
}
