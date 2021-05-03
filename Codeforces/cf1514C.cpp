#include<iostream>
using namespace std;
//accepted
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

int arr[100005];

long long int gcd(long long int a, long long int b){
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

int main(){
    fast();
    long long int n,i,pr,cnt;
    cin>>n;
    pr=1;
    cnt=0;
    for(i=1;i<n;i++){
        if(gcd(i,n)==1){
            pr*=(i%n);
            pr%=n;
            cnt++;
            // cout<<i<<" "<<pr<<"\n";
            arr[i]=1;
        }
    }
    if(pr!=1){
        arr[pr]=0;
        cnt--;
    }
    cout<<cnt<<"\n";
    for(i=1;i<n;i++){
        if(arr[i])
            cout<<i<<" ";
    }
    cout<<"\n";
}