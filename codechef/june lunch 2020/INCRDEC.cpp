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


vector<int>v1;
vector<int>v2;
int n,inp[200005],mapi[200005];

int gt(int a, int b)
{
    return a>b;
}
DN
{
    fast();
    inout();

    int flag;

    test()
    {
        flag=1;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>inp[i];

        for(int i=0;i<n;i++)
        {
            if(mapi[inp[i]]==0)
            {
                v1.push_back(inp[i]);
                mapi[inp[i]]++;
            }
            else if(mapi[inp[i]]==1)
            {
                v2.push_back(inp[i]);
                mapi[inp[i]]++;
            }
            else
            {
                flag=0;
                break;
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<int>());
        if(v2.size()>0)
        {
            if(v1[v1.size()-1]==v2[0])
                flag=0;
        }

        if(flag)
        {
            cout<<"YES\n";
            for(int i=0;i<v1.size();i++)
                cout<<v1[i]<<" ";
            for(int i=0;i<v2.size();i++)
                cout<<v2[i]<<" ";
            cout<<endl;
        }
        else
            cout<<"NO"<<endl;

        for(int i=0;i<n;i++)
            mapi[inp[i]]=0;
        v1.clear();
        v2.clear();
    }

    return 0;
}
