#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}


int main(){
    inout();
    fast();
    string inp;
    int arr[300005];
    int n, tp, i, rm, now, cnt,arranged;

    cin>>n;
    rm=1;
    tp=0;
    cnt=0;
    arranged = 0;
    for(i=1;i<=(2*n);i++){
        cin>>inp;

        if(inp=="add"){
            cin>>arr[tp++];
            // cout<<tp<<" "<<arr[tp-1]<<" "<<i<<" "<<n<<"\n";
            // if(arr[tp-1]!=rm+1)
            //     arranged = 0;
        }
        else{
            if(arr[tp-1]==rm){
                tp--;
                rm++;
                // if(arranged){
                //     arr[tp-1] = rm;
                // }
            }
            else{
                // arranged = 1;
                tp--;
                rm++;
                for(int j=tp-1,x=rm;j>=0;j--,x++){
                    arr[j]=x;
                }
                // arr[tp-1] = rm;
                cnt++;
            }
        }
    }

    cout<<cnt<<"\n";
}