#include<iostream>
using namespace std;

int main(){

    long long int n,even,odd,ans;

    cin>>n;

    even = n/2;
    odd = n-even;

    ans = (even*(even+1))-odd*odd;

    cout<<ans<<endl;
}
