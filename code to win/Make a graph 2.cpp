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

int pMap[505],pStat[1005],primes[505];
int arr[mx],sets[mx];

int doSeive()
{
    pStat[1]=1;
    int pCnt=0;
    primes[pCnt++]=2;

    for(int i=4;i<=1000;i+=2)
        pStat[i]=1;

    for(int i=3;i<=1000;i+=2){
        if(!pStat[i]){
            for(int j=i*i;j<=1000;j+=i){
                  pStat[j]=1;
            }
            primes[pCnt++]=i;
        }
    }

    return pCnt;
}

int findSet(int a){
    if(sets[a]==a)return a;

    sets[a] = findSet(sets[a]);

    return sets[a];
}

void check(int a, int b){
    int x = findSet(a);
    int y = findSet(b);

    if(x!=y)
        sets[x]=y;
}

DN
{
    fast();
    //inout();

    int n,tk,tp,i,j;
    set<int> fi;

    tp = doSeive();

    tk=0;
    test(){
        tk++;
        cin>>n;
        for(i=0;i<n;i++){
            sets[i]=i;
            cin>>arr[i];
        }

        for(i=0;i<tp;i++)
            pMap[i]=-1;

        for(i=0;i<n;i++){
            j=0;
            while(primes[j]<=arr[i] && j<tp){
                if(arr[i]%primes[j]==0){
                    if(pMap[j]!=-1)
                        check(i,pMap[j]);
                    pMap[j]=i;
                }
                j++;
            }
        }

        if(!fi.empty())
            fi.clear();

        for(i=0;i<n;i++)
            fi.insert(findSet(i));

        cout<<"Case "<<tk<<": "<<fi.size()<<nn;
    }
    return 0;
}
