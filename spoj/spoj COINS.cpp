#include<iostream>
using namespace std;

#define li          long long int
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mx          100000000
li mem[mx];

li getVal(li n)
{
    li temp;
    if(n<mx)
    {
        if(mem[n] != -1)
            return mem[n];
    }

    temp = getVal(n/2)+getVal(n/3)+getVal(n/4);

    temp = temp>n?temp:n;

    if(n<mx)
        mem[n]=temp;
    return temp;
}


int main(){
    li n,ans;

    for(li i=1; i<mx; i++)
        mem[i]=-1;
    while(cin>>n){
        ans = getVal(n);
        cout<<ans<<endl;
    }
    return 0;
}
