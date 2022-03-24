#include<iostream>
#include<string>
//accepted
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

string a;
int t,flag,cng,sz,cng2;

string doOdd(){
    cng=0;
    flag = 0;
    for(int i=sz/2+1;i<sz;i++){
        int j = sz-i-1;
        // cout<<i<<" "<<j<<"\n";
        if(a[i]<a[j]){
            a[i] = a[j];
            cng=1;
            flag=1;
        }
        else if(a[i]>a[j]){
            a[i] = a[j];
            cng = 1;
        }
    }
    if(!cng || !flag){
        int i=sz/2;
        if(a[i]=='9'){
            flag=1;
            a[i]='0';
        }
        else
            a[i]++;
        if(flag){
            for(int i=sz/2-1;i>=0 && flag;i--){
                int j = sz-i-1;
                if(a[i]=='9'){
                    a[i]=a[j]='0';
                }
                else{
                    a[i]++;
                    a[j]++;
                    flag=0;
                }
            }
            if(flag){
                a.push_back('1');
                a[0]='1';
            }
        }
    }
    return a;
}
string doEven(){
    cng=0;
    flag = 0;
    cng2=0;
    for(int i=sz/2;i<sz;i++){
        int j = sz-i-1;
        // cout<<i<<" "<<j<<"\n";
        if(a[i]<a[j]){
            cng=1;
            a[i] = a[j];
            flag=1;
            cng2=0;
        }
        else if(a[i]>a[j]){
            if(!flag){
                flag = 1;
                a[j] = (a[i]+a[j]+1)/2;
            }
            a[i] = a[j];
            cng = 1;
        }
        else{
            if(!flag){
                flag=1;
                cng2=1;
            }
        }
    }
    if(!cng || cng2 ){
        if(flag){
            for(int i=sz/2-1;i>=0 && flag;i--){
                int j = sz-i-1;
                if(a[i]=='9'){
                    a[i]=a[j]='0';
                }
                else{
                    a[i]++;
                    a[j]++;
                    flag=0;
                }
            }
            if(flag){
                a.push_back('1');
                a[0]='1';
            }
        }
    }
    return a;
}

int main(){
    inout();
    cin>>t;
    while(t--){
        cin>>a;
        sz = a.size();
        if(sz&1)
            a = doOdd();
        else
            a = doEven();
        
        cout<<a<<"\n";
    }
    return 0;
}