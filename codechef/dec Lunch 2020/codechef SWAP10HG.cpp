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


DN
{
    fast();
    //inout();

    int cnt[2],flag,i,n;
    char s[100005],p[100005];

    test(){
        cin>>n;
        cin>>s>>p;

        cnt[0]=cnt[1]=0;
        flag=1;
        ff(0,n){
            if(p[i]=='1' && s[i]=='0'){
                if(cnt[1]>0)
                    cnt[1]--;
                else{
                    flag=0;
                    break;
                }
            }
            else if(p[i]=='0' && s[i]=='1')
                cnt[1]++;
        }

        if(flag==0 || cnt[1]!=0){
            cout<<"No\n";
            continue;
        }
        flag=1;
        bf(n-1,-1){
            if(p[i]=='0' && s[i]=='1'){
                if(cnt[0]>0)
                    cnt[0]--;
                else{
                    flag=0;
                    break;
                }
            }
            else if(p[i]=='1' && s[i]=='0')
                cnt[0]++;
        }

        if(flag==0 || cnt[0]!=0){
            cout<<"No\n";
            continue;
        }

        cout<<"Yes\n";
    }

    return 0;
}
