#include<iostream>
#define mx 100005
#define li long long int
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

li seg[3*mx],arr[mx];
li n,q;

void buildIt(li pos, li x, li y){
    seg[pos]=0LL;
    if(x==y){
        seg[pos]=arr[x];
        return;
    }

    li md = (x+y)/2;
    buildIt(pos*2,x,md);
    buildIt(pos*2+1,md+1,y);

    seg[pos] = seg[pos*2]+seg[pos*2+1];
    // cout<<pos<<" "<<seg[pos]<<"\n";
}

void upIt(li pos, li x, li y,li p, li v){
    // seg[pos]=0LL;
    if(x>p || y<p)
        return;
    if(x==y){
        seg[pos]+=v;
        return;
    }

    li md = (x+y)/2;
    if(p<=md)
        upIt(pos*2,x,md,p,v);
    else
        upIt(pos*2+1,md+1,y,p,v);

    seg[pos] = seg[pos*2]+seg[pos*2+1];
    // cout<<pos<<" "<<seg[pos]<<"\n";
}


li sumIt(li pos, li x, li y, li i, li j){
    if(j<x || i>y)
        return 0;
    if(i<=x && y<=j)
        return seg[pos];
    
    li md = (x+y)/2;
    return sumIt(pos*2,x,md,i,j)+sumIt(pos*2+1,md+1,y,i,j);
}


void testC(li t){
    li tp,x,y,v;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildIt(1,0,n-1);
    cout<<"Case "<<t<<":\n";
    for(int i=0;i<q;i++){
        // cout<<"\n";
        cin>>tp;
        if(tp==1){
            cin>>x;
            v = arr[x]*(-1);
            cout<<arr[x]<<'\n';
            arr[x]=0;
            upIt(1,0,n-1,x,v);
        }
        else if(tp==2){
            cin>>x>>v;
            arr[x]+=v;
            upIt(1,0,n-1,x,v);
        }
        else{
            cin>>x>>y;
            cout<<sumIt(1,0,n-1,x,y)<<"\n";
        }
    }
}

int main(){
    inout();
    li t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        testC(tc);
    }
}