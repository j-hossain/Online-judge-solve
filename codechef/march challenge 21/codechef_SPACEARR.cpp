#include<iostream>
#include<algorithm>
using namespace std;
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);
//accepted


int main(){
    // fast();
    long long int n,t,arr[200005],s1,s2,i,diff;

    cin>>t;
    while(t--){
        cin>>n;
        diff = 0;
        for(i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr,arr+i);

        for(i=0;i<n;i++){
            if(arr[i]>i+1){
                diff=1;
                break;
            }
            else{
                diff+=(i+1-arr[i]);
            }
        }

        if(diff&1){
            cout<<"First\n";
        }
        else
            cout<<"Second\n";
    }
    return 0;
}