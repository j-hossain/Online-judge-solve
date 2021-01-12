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
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}

struct cc{
    li cap;
    li cost;
};

struct cc car[200005];

int comp(struct cc a, struct cc b){
    return a.cost<b.cost;
}

DN
{
    fast();
    inout();
    li n,i,dist,mxCost;
    test(){
        cin>>n;
        for(i=0;i<n;i++)
            cin>>car[i].cap;
        for(i=0;i<n;i++)
            cin>>car[i].cost;

        sort(car,car+n,comp);

        dist = mxCost = i = 0;

        while(dist!=n && i<n){
            if(car[i].cap){
                if(car[i].cap+dist<=n){
                    dist += car[i].cap;
                    mxCost += (car[i].cost * car[i].cap);
                }
                else{
                    mxCost += (car[i].cost*(n-dist));
                    dist = n;
                }
            }
            i++;
        }

        cout<<mxCost<<endl;
    }

    return 0;
}
