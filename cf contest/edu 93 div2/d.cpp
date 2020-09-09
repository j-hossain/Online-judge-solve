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
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int getMax(int a, int b, int c){

    if(a>=b && a>=c)
        return 0;
    if(b>=c && b>=a)
        return 1;
    if(c>=a && c>=b)
        return 2;
}

int getSec(int a, int b){

    if(a>b)
        return 0;
    return 1;
}

int grt(int a,int b)
{
    return a>b;
}


DN
{
    fast();
    inout();

    int rs,gs,bs,ar[205],ag[205],ab[205],r,g,b,i,mi,si;
    li temp,ans = 0LL;

    cin>>rs>>gs>>bs;

    for(i=0;i<rs;i++)
        cin>>ar[i];
    for(i=0;i<gs;i++)
        cin>>ag[i];
    for(i=0;i<bs;i++)
        cin>>ab[i];

    sort(ar,ar+rs,grt);
    sort(ag,ag+gs,grt);
    sort(ab,ab+bs,grt);

    r=g=b=ans=0;
    ar[rs]=ag[gs]=ab[bs]=0;
    while( (r<rs && g<gs) || (g<gs && b<bs) ||(r<rs && b<bs) ){

        mi = getMax(ar[r],ag[g],ab[b]);
        temp=1LL;
        if(mi==0){
            temp*=ar[r];
            r++;
            si = getSec(ag[g],ab[b]);
                if(si==0)
                {
                    temp*=ag[g];
                    g++;
                }
                else
                {
                    temp*=ab[b];
                    b++;
                }
        }
        else if(mi==1){
            temp*=ag[g];
            g++;
            si = getSec(ar[r],ab[b]);
                if(si==0)
                {
                    temp*=ar[r];
                    r++;
                }
                else
                {
                    temp*=ab[b];
                    b++;
                }
        }
        if(mi==2){
            temp*=ab[b];
            b++;
            si = getSec(ag[g],ar[r]);
                if(si==0)
                {
                    temp*=ag[g];
                    g++;
                }
                else
                {
                    temp*=ar[r];
                    r++;
                }
        }
        ans+=temp;
    }

    cout<<ans<<endl;

    return 0;
}
