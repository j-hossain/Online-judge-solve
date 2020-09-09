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
    inout();

    int arr[105],i,c,a,ans;
    char inp[105];

    test(){
        cin>>inp;
        c=a=ans=0;
        for(i=0;inp[i]!='\0';)
        {
            while(inp[i]=='1' && inp[i]!='\0')
            {
                i++;
                c++;
            }

            if(c>0)
            {
                arr[a++]=c;
                c=0;
            }
            else
                i++;
        }

        sort(arr,arr+a);

        for(i=a-1;i>=0;i-=2)
        {
            ans+=arr[i];
        }

        cout<<ans<<endl;
    }



    return 0;
}
