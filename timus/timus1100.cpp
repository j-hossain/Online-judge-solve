#include<iostream>
#include<algorithm>
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

typedef struct{
    int pos;
    int id;
    int slvd;
}per;

int cmp(per a, per b){
    if(a.slvd==b.slvd)
        return a.pos<b.pos;
    return a.slvd>b.slvd;
}

int main(){
    inout();
    per arr[150000];
    int i,n;

    cin>>n;
    for(i=0;i<n;i++){
        cin>>arr[i].id>>arr[i].slvd;
        arr[i].pos = i;
    }
    sort(arr,arr+n,cmp);
    for(i=0;i<n;i++){
        cout<<arr[i].id<<" "<<arr[i].slvd<<"\n";
    }
    return 0;
}