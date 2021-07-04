#include<iostream>
using namespace std;
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int main(){
    inout();
    int n,i,t,arr[100001],x,y,cnt;
    cin>>t;
    while(t--){
        cin>>n;
        cnt=0;
        for(i=1;i<=n;i++){
            cin>>arr[i];
        }

        for(i=1;i<=n;i++){
            x=arr[i]>i?arr[i]:i+(arr[i]-i%arr[i]);
            y=x-i;
            while(y<i){
                if(i+y==arr[i]*arr[y])
                    cnt++;
                x+=arr[i];
                y=x-i;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}