#include<iostream>
#include<set>
//accepted
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int main(){
    inout();
    int t,n,arr[200005],i,temp,lsMx;
    set<int> st1,st2;
    cin>>t;
    while(t--){

        cin>>n;
        for(i=0;i<n;i++)
            cin>>arr[i];

        for(i=1;i<=n;i++){
            st1.insert(i);
            st2.insert(i);
        }
        st1.erase(arr[0]);
        cout<<arr[0]<<' ';
        for(i=1;i<n;i++){
            if(arr[i]!=arr[i-1]){
                st1.erase(arr[i]);
                cout<<arr[i]<<" ";
            }
            else{
                temp = *st1.begin();
                cout<<temp<<" ";
                st1.erase(temp);
            }
        }
        cout<<"\n";
        st2.erase(arr[0]);
        cout<<arr[0]<<' ';
        lsMx = arr[0];
        for(i=1;i<n;i++){
            if(arr[i]!=arr[i-1]){
                st2.erase(arr[i]);
                cout<<arr[i]<<" ";
                lsMx = arr[i];
            }
            else{
                auto ttt = st2.lower_bound(lsMx);
                ttt--;
                temp = *ttt;
                // cout<<lsMx<<" "<<temp<<"\n";
                cout<<temp<<" ";
                st2.erase(temp);
                lsMx = temp;
            }
        }
        cout<<"\n";

    }
}