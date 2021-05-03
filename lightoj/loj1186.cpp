#include<iostream>
using namespace std;
//accepted

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int main(){
    inout();
    int n,w[105],b[105],i,sum,dif;
    int t,tk=0;
    cin>>t;
    while(t--){
        tk++;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>w[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        sum=0;
        for(i=0;i<n;i++){
            dif = b[i]-w[i]-1;
            sum^= dif;
        }

        cout<<"Case "<<tk<<": ";
        if(!sum)
            cout<<"black wins\n";
        else
            cout<<"white wins\n";
    }
    return 0;
}