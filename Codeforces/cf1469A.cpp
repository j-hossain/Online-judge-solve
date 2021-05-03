#include<iostream>
#include<string>
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
    string inp;
    int cnt, f1, f2, t;

    cin>>t;
    while(t--){
        cin>>inp;
        cnt=f1=f2=0;
        for(auto i: inp){
            if(i=='('){
                f1=1;
            }
            else if(i==')' && !f1){
                if(!cnt){
                    cnt=1;
                    break;
                }
                f2=1;
            }
            else if(i=='?'){
                if(f2 && f1)
                    f2=0;
                cnt++;
            }
        }

        if(cnt%2 || f2)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;

}