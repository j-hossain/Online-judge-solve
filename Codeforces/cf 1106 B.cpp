#include<iostream>
#include<algorithm>
using namespace std;

#define li long long int
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef struct st{
    li c;
    li d;
    li p;
}dish;

int comp(dish a, dish b){
    return a.c<b.c;
}

li mapi[100005];
dish ds[100005];

li getCost(li &dd, li s){
    li cost =0L;
    if(dd<=ds[s].d){
        cost=(dd)*ds[s].c;
        ds[s].d-=dd;
        dd=0;
    }
    else{
        cost=(ds[s].d)*ds[s].c;
        dd-=ds[s].d;
        ds[s].d=0;
    }
    return cost;
}

int main(){
    fast();
    li i,n,m,f,dd,mn,cost;

    cin>>n>>m;

    for(i=0;i<n;i++){
        cin>>ds[i].d;
        ds[i].p = i;
    }

    for(i=0;i<n;i++){
        cin>>ds[i].c;
    }

    sort(ds,ds+n,comp);

    for(i=0;i<n;i++){
        mapi[ds[i].p]=i;
    }

    mn=0;
    while(m--){
        cost=0;
        cin>>f>>dd;
        i = mapi[f-1];
        cost+= getCost(dd,i);
        while(dd>0 && mn<n){
            cost+=getCost(dd,mn);
            if(ds[mn].d==0)
                mn++;
        }

        if(dd!=0){
            cost=0;
        }
        cout<<cost<<"\n";
    }


}
