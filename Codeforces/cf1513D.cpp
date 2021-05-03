#include<iostream>
#include<vector>
#define ll long long int 
using namespace std;

ll arr[200005];

ll gcd(ll a, ll b){
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

int main(){
    ll n,t,p,i,gd,x;
    vector<ll> fnd;
    cin>>t;
    while(t--){
        cin>>n>>p;
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        x=-1;
        gd = gcd(arr[0],arr[1]);
        if(gd==arr[0])
            x=arr[0];
        else if(gd==arr[1])
            x=arr[1];
        fnd.push_back(arr[0]);
        fnd.push_back(arr[1]);
        for(i=2;i<n;i++){
            if(gcd(arr[i],arr[i-1])==gd){
                fnd.push_back(arr[])
            }
        }
    }

}