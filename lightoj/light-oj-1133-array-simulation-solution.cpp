#include<iostream>
using namespace std;
// for file input output
void inline inout(){
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}
int main(){
    // inout();
    int t;
    cin>>t;
    for(int tk=1;tk<=t;tk++){
        int n,q;
        cin>>n>>q;
        int arr[n+2];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        while (q--)
        {
            string tp;
            int a,b;
            cin>>tp;
            if(tp=="S"){
                cin>>a;
                for(int i=0;i<n;i++){
                    arr[i]+=a;
                }
            }
            else if(tp=="M"){
                cin>>a;
                for(int i=0;i<n;i++){
                    arr[i]*=a;
                }
            }
            else if(tp=="D"){
                cin>>a;
                for(int i=0;i<n;i++){
                    arr[i]/=a;
                }
            }
            else if(tp=="P"){
                cin>>a>>b;
                if(a==b)
                    continue;
                arr[a]=arr[a]+arr[b];
                arr[b]=arr[a]-arr[b];
                arr[a]=arr[a]-arr[b];
            }
            else{
                for(int i=0;i<n/2;i++){
                    if(i==n-i-1)
                        continue;
                    arr[i]=arr[i]+arr[n-i-1];
                    arr[n-i-1]=arr[i]-arr[n-i-1];
                    arr[i]=arr[i]-arr[n-i-1];
                }
            }
        //     for(int i=0;i<n;i++){
        //     cout<<arr[i];
        //     if(i<n-1){
        //         cout<<" ";
        //     }
        // }
        // cout<<"\n";
        }
        cout<<"Case "<<tk<<":\n";
        for(int i=0;i<n;i++){
            cout<<arr[i];
            if(i<n-1){
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}