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
    while (t--)
    {
        string s;
        cin>>s;
        cout<<"Case "<<tk<<": "<<"https://";
        int i;
        for(i=0;i<s.size();i++){
            if(s[i]=='/' and s[i+1]=='/')
                break;
        }
        i+=2;
        while(i<s.size()){
            cout<<s[i];
            i++;
        }
        cout<<"\n";
        tk++;
    }
    return 0;
}