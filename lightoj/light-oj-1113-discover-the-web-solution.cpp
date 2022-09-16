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
    int tk=1;
    string bk[106];
    string fr[106];
    string cur;
    int b,f;
    while(t--){
        cur = "http://www.lightoj.com/";
        b=f=0;
        cout<<"Case "<<tk<<":\n";
        string s;
        while(cin>>s){
            if(s=="VISIT"){
                f=0;
                bk[b++]=cur;
                cin>>cur;
                cout<<cur<<"\n";
            }
            else if(s=="BACK"){
                if(b!=0){
                    fr[f++]=cur;
                    cur=bk[--b];
                    cout<<cur<<"\n";
                }
                else{
                    cout<<"Ignored\n";
                }
            }
            else if(s=="FORWARD"){
                if(f!=0){
                    bk[b++]=cur;
                    cur = fr[--f];
                    cout<<cur<<"\n";
                }
                else{
                    cout<<"Ignored\n";
                }
            }
            else{
                break;
            }
        }
        tk++;
    }
    return 0;
}