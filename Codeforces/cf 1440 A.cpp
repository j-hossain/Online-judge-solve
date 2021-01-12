#include<iostream>
#include<string>

using namespace std;

int main(){
    int c0,c1,h,l,cn0,cn1,cw,cwo,ans,t;
    string st;

    cin>>t;
    while(t--){
        cin>>l>>c0>>c1>>h>>st;
        cn0 = cn1 = 0;

        for(int i=0; i<l; i++){
            if(st[i]=='1')
                cn1++;
            else
                cn0++;
        }

        if(c0<c1){
            swap(c0,c1);
            swap(cn0,cn1);
        }

        ans = min((c0*cn0 + c1*cn1),(cn0*(c1+h) + cn1*c1));

        cout<<ans<<endl;
    }
    return 0;
}
