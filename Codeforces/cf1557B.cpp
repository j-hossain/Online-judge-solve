#include<iostream>
#include<algorithm>
using namespace std;
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

struct point
{
    int v,i;
    bool operator<(const point &a)const{
        return v<=a.v;
    }
};


int main(){
    inout();
    point arr[100005];
    int n,t,k,mk;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>arr[i].v;
            arr[i].i = i;
        }
        sort(arr,arr+n);
        mk=1;
        for(int i=0;i<n-1;i++){
            if(arr[i+1].i-arr[i].i!=1){
                mk++;
            }
        }  


        if(k>=mk){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
    return 0;
}