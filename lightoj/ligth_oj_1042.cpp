#include<iostream>
#include<cmath>
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
    int t,n,ans,o,z,tc=1;
    cin>>t;
    while (t--)
    {
        cin>>n;
        o=0;
        z=-1;
        int i;
        for(i=0;(1<<i)<=n;i++){
            if((1<<i)&n){
                o++;
            }
            else if(o>0){
                z = i;
                break;
            }
        }
        if(z==-1)
            z = i;
        o--;
        for(i=0;i<z;i++){
            if(o>0){
                n = n|(1<<i);
                o--;
            }
            else{
                n = n&(~(1<<i));
            }
        }
        n = n|(1<<z);
        cout<<"Case "<<tc<<": "<<n<<"\n";
        tc++;
    }
    
}