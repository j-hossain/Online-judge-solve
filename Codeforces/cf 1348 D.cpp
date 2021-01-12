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

//accepted


DN
{
    fast();
    inout();

    li n,i,len,arr[100],sum,temp;

    test(){
        cin>>n;
        sum=1;
        arr[0]=1;
        len=1;
        while(sum<=n){
            temp = pow(2,len);
            if(temp+sum>n)
                break;
            else{
                sum+=temp;
                arr[len++]=temp;
            }
        }

        temp = n-sum;
        if(temp){
            i=len-1;
            while(i>0 && arr[i]>temp){
                arr[i+1]=arr[i];
                i--;
            }
            i++;
            arr[i]=temp;
            len++;
        }
        cout<<(len-1)<<nn;
        ff(1,len){
            cout<<(arr[i]-arr[i-1])<<spc;
        }
        cout<<nn;

    }

    return 0;
}
