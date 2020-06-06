#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MM          int main()
#define li          long long int
#define test        int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;
#define mx          1050

#define ff(j,s,e,r)     for(j=s;j<e;j+=r)
#define bf(j,s,e,r)     for(j=s;j>e;j-=r)


MM
{
    DEC;
    fast();
    int arr[mx],mapi[mx],m,x;
    test
    {
        cnt=0;
        cin>>n;
        i=m=0;
        ff(i,0,mx,1)
            mapi[i]=0;
        while(i<n)
        {
            cin>>arr[i++];
            mapi[arr[i-1]]=1;
            if(arr[i-1]>m)
                m=arr[i-1];
        }
        x=1;
        while(x<=m)
        {
            ff(i,0,n,1)
            {
                if(mapi[x^arr[i]]!=1)
                    break;
            }
            if(i>=n)
                break;
            x++;
        }
        ff(i,0,n,1)
            mapi[arr[i]]=0;
        if(x>m)
            cout<<"-1"<<endl;
        else
            cout<<x<<endl;
    }
    return 0;
}

