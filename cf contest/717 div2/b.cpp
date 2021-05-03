#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<set>
#include<map>
using namespace std;
//accepted

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
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}


void pagoleKinaKore(){
    li i,n,arr[2005],sum,x,temp;

    test(){
        cin>>n;
        sum=0;
        int j=0;
        for(i=0;i<n;i++){
            cin>>temp;
            if(temp>0){
                arr[j++] = temp;
                sum^=arr[i]; 
            }
        }
        n=j;
        if(sum==0){
            cout<<"YES\n";
            continue;
        }
        x=sum;
        // cout<<x<<"\n";
        sum=0LL;
        for(i=0;i<n;i++){
            sum^=arr[i];
            if(sum==x){
                i++;
                break;
            }
        }
        if(i<n-1){
            sum=0LL;
            while(i<n){
                // cout<<i<<"\n";
                sum^=arr[i++];
            }
            if(sum==0){
                cout<<"YES\n";
                continue;
            }
        }
        cout<<"NO\n";
    }
}

DN
{
    fast();
    inout();
    
    pagoleKinaKore();

    return 0;
}
