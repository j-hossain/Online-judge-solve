#include<iostream>
using namespace std;
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("G:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int main(){
    //inout();
    int t,i,c,sum;
    char inp[100];
    cin>>t;
    while(t--){
        c=sum=0;
        cin>>inp;
        for(i=0; inp[i]!='\0'; i++){
            c = inp[i]=='O'?c+1:0;
            sum+=c;
        }

        cout<<sum<<endl;
    }
    return 0;
}
