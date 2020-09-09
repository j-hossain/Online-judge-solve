#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
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
//    inout();

    int arr[100005],x,flag,i;
    char st[100005];

    test(){
        cin>>st;
        cin>>x;
        int len = strlen(st);
        for(i=1;i<=len;i++)
            arr[i]=-1;

        for(i=1;i<=len;i++){
            flag=0;
            if(st[i-1]=='1'){
                if(i>x && (arr[i-x]==-1|| arr[i-x]==1)){
                    arr[i-x]=1;
                    flag=1;
                }
                else if(i+x<=len && (arr[i+x]==-1|| arr[i+x]==1))
                {
                    arr[i+x]=1;
                    flag=1;
                }
            }
            else if(st[i-1]=='0'){
                if(i>x && (arr[i-x]==-1|| arr[i-x]==0)){
                    arr[i-x]=0;
                    flag=1;
                }
                else if(i+x<=len && (arr[i+x]==-1|| arr[i+x]==0))
                {
                    arr[i+x]=0;
                    flag=1;
                }
            }

            if(!flag)
                break;
        }

        if(flag){
            for(i=1;i<=len;i++)
            {
                if(arr[i]==-1)
                    arr[i]=0;
                    cout<<arr[i];
            }
            cout<<endl;
        }
        else
            cout<<"-1"<<endl;
    }


    return 0;
}
