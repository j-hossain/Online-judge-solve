#include<iostream>
using namespace std;
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("G:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int upBnd(int *arr, int tr,int n){
    int l = 0;
    int h = n-1;
    int m;

    while(l<=h){
       m = (l+h)/2;

       if(arr[m]>=tr)
            h = m-1;
       else
            l = m+1;
    }
    return h;
}

int lowBnd(int *arr, int tr,int n){
    int l = 0;
    int h = n-1;
    int m;

    while(l<=h){
       m = (l+h)/2;

       if(arr[m]>tr)
            h = m-1;
       else
            l = m+1;
    }
    return l;
}

int main(){
    fast();
    //inout();
    int n,q,gh[50005],lh,i,up,low;
    char mn,mx;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>gh[i];
    cin>>q;
    while(q--){
        cin>>lh;
        up = upBnd(gh,lh,n);
        low = lowBnd(gh,lh,n);

        if(gh[up]!=lh && gh[low]!=0)
            cout<<gh[up]<<" "<<gh[low]<<"\n";
        else if(gh[up]==lh && gh[low]!=0)
            cout<<"X "<<gh[low]<<"\n";
        else if(gh[up]!=lh && gh[low]==0)
            cout<<gh[up]<<" X"<<"\n";
        else
            cout<<"X X\n";
    }
    return 0;
}
