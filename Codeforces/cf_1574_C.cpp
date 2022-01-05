#include<iostream>
#include<algorithm>
using namespace std;
//accepted

#define li long long int

#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

li n,m,a[200004],x,y,ans;
li sm;

int main(){
    fast();
    inout();
    cin>>n;
    sm=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sm+=a[i];
    }
    sort(a,a+n);
    cin>>m;
    while(m--){
        cin>>x>>y;
        int mn = lower_bound(a,a+n,x)-a;
        sm-=a[mn];
        ans = x>a[mn]?(x-a[mn]):0;
        ans += y>sm?(y-sm):0;
        sm+=a[mn];
        if(mn>0){
            mn--;
            sm-=a[mn];
            y = y>sm?(y-sm):0;
            ans = min(ans,x-a[mn]+y);
            sm+=a[mn];
        }
        cout<<ans<<"\n";
    }
    return 0;
}