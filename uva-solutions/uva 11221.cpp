#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//accepted

int isSquare(int a){
    int x = sqrt(a);
    return a == x*x;
}

int isPalin(string &ts){
    int i,l = ts.size();

    for(i=0;i<l/2;i++){
        if(ts[i]!=ts[l-i-1])
            return 0;
    }
    return 1;
}

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("G:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int main(){
    //inout();

    int t,tc,i,j,l;
    string inp,filtered;

    cin>>t;
    getline(cin,inp);
    tc=0;
    while(tc<t){
        tc++;
        getline(cin,inp);
        l = inp.size();
        for(i=0;i<l;i++){
            if(inp[i]>='a' && inp[i]<='z')
                filtered.push_back(inp[i]);
        }
        l = filtered.size();
        cout<<"Case #"<<tc<<":\n";
        if(isSquare(l) && isPalin(filtered))
            cout<<(sqrt(l))<<endl;
        else
            cout<<"No magic :(\n";
        filtered.clear();
    }
    return 0;
}
