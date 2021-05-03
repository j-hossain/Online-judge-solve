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
    int n,arr[105],i,k;
    test(){
        cin>>n>>k;
        for(i=0;i<n;i++)
            cin>>arr[i];
        
        for(i=0;i<n-1;i++){
            int x = min(arr[i],k);
            k-=x;
            arr[i]-=x;
            arr[n-1]+=x;
        }

        for(i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

}

DN
{
    fast();
    inout();
    
    pagoleKinaKore();

    return 0;
}
