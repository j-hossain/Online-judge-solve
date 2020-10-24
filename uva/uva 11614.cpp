#include<iostream>
#include<cmath>
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("G:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int main(){
    inout();
    long long int n,x;
    int t;
    cin>>t;
    while(t--){
        cin>>x;
        n = (sqrt(4*2*x+1)-1)/2;
        cout<<n<<endl;
    }
    return 0;
}
