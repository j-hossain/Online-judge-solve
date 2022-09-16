#include<iostream>
#include<stack>
using namespace std;

stack<int> sta;

// for file input output
void inline inout(){
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

int main(){
    inout();
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        int n;
        cin>>n;
        int arr[n+10];
        int left[n+10];
        int right[n+10];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            if(!sta.empty()){
                while(arr[sta.top()]>=arr[i]){
                    sta.pop();
                    if(sta.empty())
                        break;
                }
                if(sta.empty()){
                    left[i]=0;
                }
                else{
                    left[i] = sta.top()+1;
                }
            }
            else{
                left[i]=0;
            }
            sta.push(i);
        }
        while (!sta.empty())
        {
            sta.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            if(!sta.empty()){
                while(arr[sta.top()]>=arr[i]){
                    sta.pop();
                    if(sta.empty())
                        break;
                }
                if(sta.empty()){
                    right[i]=n;
                }
                else{
                    right[i] = sta.top();
                }
            }
            else{
                right[i]=n;
            }
            sta.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            // cout<<right[i]<<" "<<left[i]<<"\n";
            ans = max(ans,arr[i]*(right[i]-left[i]));
        }
        cout<<"Case "<<tc<<": ";
        cout<<ans<<"\n";
        while (!sta.empty())
        {
            sta.pop();
        }
    }
    return 0;
}