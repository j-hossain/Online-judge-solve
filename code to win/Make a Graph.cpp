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

int primes[505];
int pStat[1005];

int seivePrimes()
{
    pStat[1]=1;
    int cnt=0;
    primes[cnt++]=2;
    for(int i=4; i<=1000; i+=2)
        pStat[i]=1;
    for(int i=3; i<=1000; i+=2)
    {
        if(!pStat[i])
        {
            for(int j=i*i; j<=1000; j+=i)
                pStat[j]=1;
            primes[cnt++]=i;
        }
    }

    return cnt;
}

int pMap[505],sets[mx],arr[mx];

int findP(int p)
{
    if(sets[p]==p)return p;

    sets[p]=findP(sets[p]);

    return sets[p];
}

void check(int x, int y)
{
    int u = findP(x);
    int v = findP(y);

    if(u==v)
        return;

    sets[u]=v;
}

DN
{
    set<int> fi;
    fast();
    inout();

    int tp = seivePrimes();

    int tk,n,i,j;
    tk=0;
    test()
    {
        tk++;
        cin>>n;
        ff(1,n+1)
        {
            sets[i]=i;
            cin>>arr[i];
        }
        ff(0,tp)
            pMap[i]=0;

        ff(1,n+1)
        {
            ff2(j,0,tp,1)
            {
                if(arr[i]<primes[j])
                    break;
                if(arr[i]%primes[j]==0)
                {
                    if(pMap[j]!=0)
                    {
                        check(i,pMap[j]);
                    }

                    pMap[j]=i;
                }
            }
        }
        if(!fi.empty())
            fi.clear();
        ff(1,n+1)
            fi.insert(findP(i));

        cout<<"Case "<<tk<<": "<<fi.size()<<nn;
    }

    return 0;
}
