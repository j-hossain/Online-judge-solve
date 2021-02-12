
//first or second any number can be the max one
// so calculate absolute difference only

#include<iostream>
using namespace std;

int main(){
    int a,b,res;
    while(cin>>a>>b){
        res=(a>b)?(a-b):(b-a);
        cout<<res<<"\n";
    }
    return 0;
}