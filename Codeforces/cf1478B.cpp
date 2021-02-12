#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
//not accepted

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

int check(int a,int b,int num){
    int i,tem;
    for(i=1;i<=10;i++){
        tem=i*a;
        if(tem%10==b)
            return tem;
    }
    return num+1;
}

DN
{
    fast();
    inout();
    int n,i,num,fv,dg,flag,cnt;
    test(){
        cin>>n>>fv;
        ff(0,n){
            flag=0;
            cnt=0;
            cin>>num;
            while(num && !flag){
                dg=num%10;
                if(check(fv,dg,num)<=num)
                    flag=1;
                if(dg>=fv)
                    cnt++;
                if(cnt>=2)
                    flag=1;
                num/=10;
            }
            if(flag)
                cout<<"YES\n";
            else
            {
                cout<<"NO\n";
            }
            
        }
        
    }
    return 0;
}
