
#include<iostream>
using namespace std;

int main(){
    int n,arr[106],mp[106],used,cnt;
    cin>>n;
    for(int i=0;i<n;i++){
        mp[i]=0;
        cin>>arr[i];
    }
    used=0;
    for(int i=0;i<n;i++){
        cnt=0;
        if(mp[i]==0){
            mp[i]=used++;
        }

        for(int j=0;j<n;j++){
            if(j!=i){
                if(mp[j]!=mp[i])
                    cnt++;
                else if(mp[j]==0)
                    mp[j]=mp[i];
            }4
        }
    }
}