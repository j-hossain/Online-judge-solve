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


DN
{
    fast();
//    inout();

    int p,f,cs,cw,s,w,cnt;
    int c1,c2,w1,w2,flag;

    test(){
        cin>>p>>f;
        cin>>cs>>cw;
        cin>>s>>w;
        cnt=0;

        if(s<w){
            c1=cs;
            c2=cw;
            w1=s;
            w2=w;
        }
        else{
            c1=cw;
            c2=cs;
            w1=w;
            w2=s;
        }

        while(c1||c2){
            flag=0;
            if(f>p){

                if(c1 && f>=w1){
                    flag=1;
                    f-=w1;
                    c1--;
                    cnt++;
                }
                else if(f>=w2){
                    flag=1;
                    f-=w2;
                    c2--;
                    cnt++;
                }
            }
            else{

                if(c1 && p>=w1){
                    flag=1;
                    p-=w1;
                    c1--;
                    cnt++;
                }
                else if(p>=w2){
                    flag=1;
                    p-=w2;
                    c2--;
                    cnt++;
                }
            }

            if(!flag)
                break;
        }

        cout<<cnt<<endl;
    }



    return 0;
}
