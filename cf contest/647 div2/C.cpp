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
#define mx          100005

#define ff(j,s,e,r)     for(j=s;j<e;j+=r)
#define bf(j,s,e,r)     for(j=s;j>e;j-=r)


MM
{
    fast();
    li n,ans;
    int mn,x,temp;
    test{
        cin>>n;
        if(n==1)
        {
            cout<<"1"<<endl;
            continue;
        }

        else
            x=log2(n);
        ans=pow(2,x+1)-1;
        if(pow(2,x)<n)
        {
            mn=pow(2,x);
            while(x>=0)
            {
                mn+=(pow(2,x-1));
                if(mn<=n){
                   temp=pow(2,x-1)-1;
                   ans+= (temp+1)/2+(temp/2)*2;
                   ans+=x;
                   if(mn==n)
                    break;
                }
                else
                {
                    mn-=pow(2,x-1);
                    temp = n-mn;
                    ans+= (temp+1)/2+(temp/2)*2;
                    break;
                }
                x--;
            }
        }
            cout<<ans<<endl;
    }
}
