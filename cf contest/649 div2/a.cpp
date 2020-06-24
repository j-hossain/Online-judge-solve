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

    li n,x,i,sum,arr[100005],lenght,flag;

    test()
    {
        cin>>n>>x;
        sum=lenght=flag=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            if(arr[i]%x!=0)
                flag=1;
        }
        if(sum%x!=0)
        {
            cout<<n<<endl;
            continue;
        }
        if(!flag)
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(i=0;i<n;i++)
        {
            if(arr[i]%x!=0)
                break;
        }
        lenght=(i+1)>(n-i-1)?(i+1):(n-i-1);
        for(i=n-1;i>=0;i--)
        {
            if(arr[i]%x!=0)
                break;
        }
        i=(n-i)>i?(n-i):i;
        if(i>lenght)
            lenght=i;
        cout<<lenght<<endl;
    }


    return 0;
}
