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


int arr[1050],mapi[1050],m,x;
int i,n;

int main()
{
    fast();
    test
    {
        cin>>n;
        i=m=0;
        while(i<n)
        {
            cin>>arr[i];
            mapi[arr[i]]=1;
            if(arr[i]>m)
                m=arr[i];

            i++;
        }
        x=1;
        while(x<=m)
        {
            for(i=0;i<n;i++)
            {
                if(mapi[x^arr[i]]!=1)
                    break;
            }
            if(i>=n)
                break;
            x++;
        }
        for(i=0;i<n;i++)
            mapi[arr[i]]=0;
        if(x>m)
            cout<<"-1"<<endl;
        else
            cout<<x<<endl;
    }
    return 0;
}

