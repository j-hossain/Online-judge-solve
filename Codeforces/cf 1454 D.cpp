#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long int t, n, ci, mxi, mxp, i, sq;
    long long int arr[100],mp;
    cin>>t;
    while(t--){
        cin>>n;
        sq = sqrt(n);
        mp = 0;
        long long int temp = n;
        for(i=2; i<=sq && temp; i++){
            if(!(temp%i)){
                while(!(temp%i)){
                    temp/=i;
                    arr[mp++] = i;
                }
            }
        }

        if(temp>1){
            arr[mp++] = temp;
        }

        arr[mp] = 0;
        ci = 0;
        mxi = 0;
        mxp = 0;
        for(i=0; i<mp; i++){
            if(arr[i+1]==arr[i])
                ci++;
            else{
                ci++;
                if(ci>mxi){
                    mxi = ci;
                    mxp = arr[i];
                }
                ci = 0;
            }
        }

        mp = 1;
        cout<<mxi<<endl;
        for(i=0; i<mxi-1; i++){
            mp *= mxp;
            cout<<mxp<<" ";
        }
        cout<<(n/mp)<<endl;
    }
    return 0;
}
