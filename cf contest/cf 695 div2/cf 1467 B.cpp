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

int arr[300005],mapi[300005],n;

int addIt(int i){
    if(i>0 & i<n-1)
        return ((arr[i]>arr[i-1] && arr[i]>arr[i+1]) || (arr[i]<arr[i-1] && arr[i]<arr[i+1]));
    return 0;
}


DN
{
    fast();
    inout();

    int i,mcnt,cnt,temp,x;
    x=0;
    test(){
        x++;
        cin>>n;
        ff(0,n){
            cin>>arr[i];
            mapi[i]=0;
        }
        cnt=0;

        ff(1,n-1){
            if(addIt(i)){
                cnt++;
                mapi[i]=1;
            }
        }
        mcnt=0;
        ff(1,n-1){
            x = arr[i];
            arr[i]=arr[i-1];
            temp = mapi[i-1]+mapi[i]+mapi[i+1]-(addIt(i-1)+addIt(i)+addIt(i+1));
            if(mcnt<temp)
                mcnt=temp;
            arr[i]=arr[i+1];
            temp = mapi[i-1]+mapi[i]+mapi[i+1]-(addIt(i-1)+addIt(i)+addIt(i+1));
            if(mcnt<temp)
                mcnt=temp;
            arr[i] = x;
        }

        cout<<(cnt-mcnt)<<nn;


    }

    return 0;
}
