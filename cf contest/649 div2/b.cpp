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

int dif(int a, int b)
{
    return a<b?(b-a):(a-b);
}

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

vector<int>ans;

MM
{
    fast();
    inout();

    int n,arr[100005],i,sum,cnt,temp;

    test()
    {
        ans.clear();
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ans.push_back(arr[0]);
        for(i=1;i<n;i++)
        {
            temp=i-1;
            if(arr[i]<=arr[i-1])
            {
                while(arr[i]<=arr[i-1] && i<n)
                    i++;
            }
            else if(arr[i]>arr[i-1])
            {
                while(arr[i]>arr[i-1] && i<n)
                    i++;
            }
            i--;
            ans.push_back(arr[i]);
        }

        cout<<ans.size()<<endl;
        for(i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }


    return 0;
}
