#include<iostream>
#include<set>
using namespace std;
//accepted
int main(){
    set<int> st;
    int n,temp,x,ans,t;
    cin>>t;
    while(t--){
        cin>>n>>x;
        st.clear();
        for(int i=0;i<n;i++){
            cin>>temp;
            st.insert(temp);
        }

        ans = st.size();
        if(n-ans<x){
            ans-= x-(n-ans);
        }

        cout<<ans<<"\n";
    }
    return 0;
}