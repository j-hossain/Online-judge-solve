#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
//accepted


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
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

typedef struct{
    int dNum;
    int aNum;
    vector<int> avlbl;
}day;

int cmp(day a, day b){
    return a.aNum<b.aNum;
}

day days[100006];
int dCnt[100006];
int assigned[100006];

DN
{
    fast();
    inout();
    int n,m,i,temp,mxPsbl,flag,flag2,frnd;
    test(){
        cin>>n>>m;
        mxPsbl = (m+1)/2;
        for(i=0;i<=n;i++)
            dCnt[i]=0;
        for(i=0;i<m;i++){
            cin>>days[i].aNum;
            days[i].dNum=i;
            assigned[i]=-1;
            days[i].avlbl.clear();
            for(int j=0;j<days[i].aNum;j++){
                cin>>temp;
                days[i].avlbl.push_back(temp);
            }
        }

        sort(days,days+m,cmp);
        flag2=1;
        for(i=0;i<m;i++){
            flag=0;
            for(int j=0;j<days[i].aNum;j++){
                frnd = days[i].avlbl[j];
                if(dCnt[frnd]<dCnt[flag] || flag==0)
                    flag=frnd;
            }

            if(flag==0 || dCnt[flag]>=mxPsbl){
                flag2=0;
                break;
            }
            else{
                assigned[days[i].dNum]=flag;
                dCnt[flag]++;
            }
        }

        if(!flag2){
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
        for(i=0;i<m;i++){
            cout<<assigned[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
