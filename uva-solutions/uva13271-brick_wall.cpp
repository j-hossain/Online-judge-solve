#include<iostream>
using namespace std;
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int main(){
    inout();
    int sx,sy,ex,ey,tempx,ans;
    while(cin>>sx>>sy>>ex>>ey){
        if(sx==sy && ex==ey && sx+ex==0)
            break;

        if(sx>ex){
            swap(sx,ex);
            swap(sy,ey);
        }
        if(sy>ey){
            ey = 2*sy-ey;
        }

        if(sx==ex){
            cout<<(ey-sy)<<"\n";
            continue;
        }

        if(ex-sx<=ey-sy){
            cout<<((ex-sx)+(ey-sy))<<"\n";
            continue;
        }

        tempx = sy+ex-ey;
        ans = ((tempx-sx)/2)*4+((sx%2!=sy%2)*2+1)*((tempx-sx)%2);
        ans+=(ey-sy)*2;

        cout<<ans<<"\n";
    }
}