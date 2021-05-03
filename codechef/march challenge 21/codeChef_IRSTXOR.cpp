#include<iostream>
#include<cmath>
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
    fast();
    // inout();
    long long int a,b,c,t,bitBit,i;
    cin>>t;
    while (t--)
    {
        /* code */
        cin>>c;
        bitBit = log2(c);
        a=b=0;
        for(i=pow(2,bitBit);i>0;i/=2){
            if(c&i){
                if(a>b)
                    b = b|i;
                else
                    a = a|i;
            }
            else{
                b = b|i;
                a = a|i;
            }
        }

        cout<<(a*b)<<"\n";
    }
    
}