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

#define DEC         int i,n,j,cnt=0,flag;
#define mx          100005

#define ff(s,e)         for(i=s;i<e;i+=r)
#define bf(s,e)         for(i=s;i>e;i-=r)
#define ff2(j,s,e,r)    for(j=s;j<e;j+=r)
#define bf2(j,s,e,r)    for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}

int solve(int n){


}

int arr[200005];
int ma[200005];
int cnt[200005];

DN
{
    fast();
    inout();
    int n,ans,mn,mni;
    for(int i=0;i<200005;i++){
        cnt[i]=0;
        ma[i]=-1;
    }
    test(){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];

        for(int i=0;i<n;i++){
            if(ma[arr[i]]==-1){
                ma[arr[i]]=i;
                if(i<n-1)
                    cnt[arr[i]]++;
                if(i>0)
                    cnt[arr[i]]++;
            }

            else{
                if(i-ma[arr[i]]>1)
                    cnt[arr[i]]++;
                if(i==n-1)
                    cnt[arr[i]]--;
                ma[arr[i]]=i;
            }
        }
        mn=200006;
        for(int i=0;i<n;i++){
            if(cnt[arr[i]]<mn)
                mn=cnt[arr[i]];
        }

        for(int i=0;i<n;i++){
            ma[arr[i]]=-1;
            cnt[i]=0;
        }
        cout<<mn<<endl;
    }

    return 0;
}
