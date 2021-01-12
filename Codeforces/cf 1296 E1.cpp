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

typedef struct abc{
    char ch;
    int pos;
    int col;
}node;

int findCol(node *arr, int p, char ch){

    for(int i=p-1;i>=0;i--){
        if(arr[i].ch>ch && arr[i].col!=-1){

            return arr[i].col^1;
        }

    }
    return 1;
}

int posi(node a, node b){
    return a.pos<b.pos;
}


DN
{
    fast();
    inout();
    int n,i,j,flag;
    node arr[305];

    cin>>n;
    ff(0,n){
        cin>>arr[i].ch;
        arr[i].pos=i;
        arr[i].col = -1;
    }
    flag=1;
    for(i=1;i<n;i++){
        if(arr[i].ch<arr[i-1].ch){
            j=i;
            arr[j].col = findCol(arr,j,arr[j].ch);
            flag=1;
            while(j>0 && arr[j-1].ch>arr[j].ch){
                if(arr[j-1].col==arr[j].col){
                    flag=0;
                    break;
                }
                if(arr[j-1].col==-1)
                    arr[j-1].col=arr[j].col^1;
                swap(arr[j-1],arr[j]);
                j--;
            }
            if(!flag)
                break;
        }
    }

        if(!flag)
            cout<<"NO\n";
        else{
            cout<<"YES\n";
            sort(arr,arr+n,posi);

            ff(0,n){
                if(arr[i].col==-1)
                    arr[i].col=0;
                cout<<arr[i].col;
            }
            cout<<nn;
        }
    return 0;
}
