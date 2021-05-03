#include<iostream>
#include<deque>
using namespace std;
//accepted

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int main(){
    inout();
    int t,n,q,arr[55],qi,i,pos,inp[300005],temp;

    cin>>n>>q;
    for(i=1;i<=50;i++)
        arr[i]=300010;
    for(i=0;i<n;i++){
        cin>>inp[i];
        if(i+1<arr[inp[i]])
            arr[inp[i]]=i+1;        
    }

    for(qi=0;qi<q;qi++){
        cin>>temp;
        pos = arr[temp];

        for(i=1;i<=50;i++){
            if(arr[i]<pos){
                arr[i]++;
            }
        }

        arr[temp] = 1;

        cout<<pos<<" ";
    }
    cout<<"\n";
    return 0;
}