#include<iostream>
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int main(){
    inout();
    int t,k,x,y,i;
    cin>>t;
    while(t--){
        cin>>k;
        for(i=1;i<100;i++){
            x = k*i;
            y =x/100;
            // cout<<x<<" "<<y<<"\n";
            if(x==y*100){
                break;
            }
        }
        cout<<i<<"\n";
    }
}