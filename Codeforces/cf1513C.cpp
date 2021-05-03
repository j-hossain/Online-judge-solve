#include<iostream>
#define li long long int
#define md 1000000007
using namespace std;

#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

li mem[200005];

void getAns(){
    for(int i=0;i<9;i++)
        mem[i] = 2LL;
    mem[9] = 3LL;

    for(int i=10;i<200005;i++)
        mem[i] = (mem[i-9]%md +mem[i-10]%md)%md;
}

int main(){
    inout();
    fast();
    li ans, n, m, i, dig;
    int t;
    cin>>t;
    getAns();
    while(t--){
        cin>>n>>m;
        ans=0LL;
        while(n>0){
            dig =n%10;
            if(m+dig<10){
                ans = (ans%md + 1)%md;
            }
            else{
                ans=((ans%md)+mem[(m+dig-10)]%md)%md;
            }
            n/=10;
        }
        cout<<ans<<"\n";
    }
    return 0;
}