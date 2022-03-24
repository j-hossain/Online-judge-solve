#include<iostream>
#include<string>
#include<map>
using namespace std;
//accepted

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int main(){
    inout();
    string inp, sub, ans;
    map<string,int> mp;
    long long int n,mx;
    while(cin>>n){
        sub.clear();
        mp.clear();
        cin>>inp;
        for(int i=0;i<n;i++){
            sub.push_back(inp[i]);
        }
        mp[sub]++;
        for(int i=n;i<inp.size();i++){
            sub.erase(sub.begin());
            sub.push_back(inp[i]);
            mp[sub]++;
        }
        mx=0;
        for(auto i:mp){
            if(i.second>mx){
                ans = i.first;
                mx = i.second;
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}