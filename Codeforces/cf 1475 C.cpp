#include<iostream>
using namespace std;

#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int a,b,k,i,ma[200005],mb[200005],u[200005],v[200005];

int main()
{
    fast();
    inout();

    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>k;
        for(i=0;i<k;i++)
        {
            cin>>u[i];
            ma[u[i]]=0;
        }
        for(i=0;i<k;i++)
        {
            cin>>v[i];
            mb[v[i]]=0;
        }
        for(i=0;i<k;i++)
        {
            ma[u[i]]++;
            mb[v[i]]++;
        }
        long long int ans=0LL;
        for(i=0;i<k;i++)
        {
            ans+=(k-ma[u[i]]-mb[v[i]]+1);
        }

        ans/=2;
        cout<<ans<<"\n";

    }
    return 0;
}
