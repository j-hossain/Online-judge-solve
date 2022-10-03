#include<bits/stdc++.h>
using namespace std;

// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        int arr[] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,
        1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,
        47045881, 64000000 ,85766121};
        int flag=0;
        for(int i=0;i<21;i++){
            if(arr[i]==n){
                cout<<"Special\n";
                flag=1;
                break;
            }
        }
        if(!flag){
            cout<<"Ordinary\n";
        }
    }

    return 0;
}