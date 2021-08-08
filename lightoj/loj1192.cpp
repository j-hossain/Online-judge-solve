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
    // inout();
    int t,n,i,sum,flag,tk=0,x1,x2,temp;
    cin>>t;
    while(t--){
        tk++;
        cin>>n;
        sum=flag=0;
        for(i=0;i<2*n;i++){
            cin>>temp;
            if(!flag){
                x1=temp;
                flag=1;
            }
            else{
                x2=temp;
                int d = x2-x1-1;
                sum^=d;
                flag=0;
            }
        }
        cout<<"Case "<<tk<<": ";
        if(!sum)
            cout<<"Bob\n";
        else
        cout<<"Alice\n";

    }
    return 0;
}