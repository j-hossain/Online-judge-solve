#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

#define DN          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define mx          100005
#define spc         ' '
#define nn          "\n"

#define ff(s,e)         for(i=s;i<e;i++)
#define bf(s,e)         for(i=s;i>e;i--)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)


void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}

typedef struct st{
    li num;
    li cnt;
}nd;

nd arr[400005];

DN
{
    fast();
    inout();

    li n,i,sum,ls,x;

    test(){
        cin>>n>>x;
        ls=n;
        sum=0LL;
        ff(0,n){
            cin>>arr[i].num;
            arr[i].cnt=1;
        }

        ff(0,ls){
            if(arr[i].num%x==0){
                sum+=((li)arr[i].num*arr[i].cnt);
                if(arr[ls-1].num!=arr[i].num/x){
                    arr[ls].num = arr[i].num/x;
                    arr[ls].cnt = arr[i].cnt*x;
                    ls++;
                }
                else
                    arr[ls-1].cnt+=(arr[i].cnt*x);

            }

            else
                break;
        }

        while(i<ls){
            sum+=((li)arr[i].num*arr[i].cnt);
            i++;
        }

        cout<<sum<<nn;
    }

    return 0;
}
