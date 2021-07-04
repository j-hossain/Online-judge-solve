#include<iostream>
using namespace std;

#define mx 100005
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int seg[3*mx],n;
int prop[3*mx];

int flipCoin(int st, int en, int x, int y, int pos){
    if(prop[pos]){
        seg[pos] = (en-st+1)-seg[pos];
        if(st!=en){
            prop[pos*2]^=1;
            prop[pos*2+1]^=1;
        }
        prop[pos]=0;
    }
    if(st>y || en<x)
        return seg[pos];
    if(st>=x && en<=y){
        seg[pos] = (en-st+1)-seg[pos];
        if(st!=en){
            prop[pos*2]^=1;
            prop[pos*2+1]^=1;
        }
        return seg[pos];
    }
    int mid = (st+en)/2;
    seg[pos] = flipCoin(st,mid,x,y,pos*2) + flipCoin(mid+1,en,x,y,pos*2+1);
    return seg[pos];
}

int howMany(int st, int en, int x, int y, int pos){
    if(prop[pos]){
        seg[pos] = (en-st+1)-seg[pos];
        if(st!=en){
            prop[pos*2]^=1;
            prop[pos*2+1]^=1;
        }
        prop[pos]=0;
    }
    if(st>y || en<x)
        return 0;
    if(st>=x && en<=y)
        return seg[pos];

    int mid = (st+en)/2;
    int ans = howMany(st,mid,x,y,pos*2) + howMany(mid+1,en,x,y,pos*2+1);
    return ans;
}

int main(){
    inout();
    int q,i,typ,a,b;
    cin>>n>>q;
    while(q--){
        cin>>typ>>a>>b;
        if(typ==0){
            flipCoin(0,n-1,a,b,1);
            // cout<<"seg: ";
            // for(i=1;i<=13;i++)
            //     cout<<seg[i]<<" ";
            // cout<<"\n";
            // cout<<"prop: ";
            // for(i=1;i<=13;i++)
            //     cout<<prop[i]<<" ";
            // cout<<"\n";
        }
        else{
            cout<<howMany(0,n-1,a,b,1)<<"\n";
            // cout<<"seg: ";
            // for(i=1;i<=13;i++)
            //     cout<<seg[i]<<" ";
            // cout<<"\n";
            // cout<<"prop: ";
            // for(i=1;i<=13;i++)
            //     cout<<prop[i]<<" ";
            // cout<<"\n";
        }
    }
    return 0;
}