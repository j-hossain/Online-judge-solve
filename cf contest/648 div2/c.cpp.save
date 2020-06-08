#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MM          int main()
#define li          long long int
#define test()      int t;cin>>t;while(t--)
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

#define DEC         int i,n,j,cnt=0,flag;

#define ff(j,s,e,r)     for(j=s;j<e;j+=r)
#define bf(j,s,e,r)     for(j=s;j>e;j-=r)

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}


int temp,n,i,j,map1[200005],map2[200005],mapPos[200005],mapNeg[200005],mx;
int arr1[200005],arr2[200005],dif1,dif2;

MM
{
    fast();
    inout();

        cin>>n;

        for(i=0;i<n;i++)
        {
            cin>>arr1[i];
            map1[arr1[i]]=i;
        }
        for(i=0;i<n;i++)
        {
            cin>>arr2[i];
            map2[arr2[i]]=i;
        }
        mx=0;
        for(i=0;i<n;i++)
        {
            temp=arr1[i];
            dif1 = map1[temp]-map2[temp];
            if(dif1<0)
            {
                dif1=-dif1;
                mapNeg[dif1]++;
                if(mapNeg[dif1]>mx)
                    mx=mapNeg[dif1];
                dif2=n-dif1;
            }
            else
            {
                mapPos[dif1]++;
                if(mapPos[dif1]>mx)
                    mx=mapPos[dif1];
                dif2=dif1-n;
            }
            if(dif2<0)
            {
                dif2=-dif2;
                mapNeg[dif2]++;
                if(mapNeg[dif2]>mx)
                    mx=mapNeg[dif2];
            }
            else
            {
                mapPos[dif2]++;
                if(mapPos[dif2]>mx)
                    mx=mapPos[dif2];
            }
        }

        cout<<mx<<endl;
    return 0;
}
