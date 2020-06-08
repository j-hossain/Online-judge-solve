#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
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

typedef struct
{
    int vl;
    int po;
}ele;

int iff(ele a, ele b)
{
    return a.vl<b.vl;
}

MM
{
    fast();
    inout();

    int n,i,j,temp,flag;
    ele arr[505];
    int type[505],arr2[505];

    test()
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>arr[i].vl;
            arr[i].po=i;
            arr2[i]=arr[i].vl;
        }
        for(i=0;i<n;i++)
        {
            cin>>type[i];
        }


        sort(arr,arr+n,iff);

        flag=1;
        for(i=0;i<n;i++)
        {
            if(arr[i].vl!=arr2[i])
            {
                j=i;
                while(type[arr[j].po]==type[j])
                {
                    j=arr[j].po;
                    if(j==i)
                        break;
                }
                if(type[arr[j].po]==type[j])
                    flag=0;
            }
        }

        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
