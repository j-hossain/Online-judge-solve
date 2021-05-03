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
    int i,sum;
    char decoded;
    string inp;
    getline(cin,inp);

    while(1){
        getline(cin,inp);
        if(inp=="___________")
            break;
        for(i=0;i<11;i++){
            if(inp[i]=='|' || inp[i]=='.')
                inp.erase(inp.begin()+i);
        }
        sum=0;
        for(i=0;i<8;i++){
            if(inp[i]=='o'){
                sum+=(1<<(7-i));
            }
        }
        // cout<<sum<<"\n";
        decoded = sum;
        cout<<decoded;
    }   
    return 0; 
}