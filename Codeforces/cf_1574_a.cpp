#include<iostream>
#include<algorithm>
using namespace std;
//accepted
int main(){
    int a[3],d,t,m1,m2;
    cin>>t;
    while (t--)
    {
        cin>>a[0]>>a[1]>>a[2]>>d;
        m1 = a[0]+a[1]+a[2]-3;
        sort(a,a+3);
        m2 = a[2]-1-(a[0]+a[1]);
        if(m1>=d && m2<=d){
            cout<<"Yes\n";
        }
        else    
            cout<<"NO\n";
    }
    return 0;
}



