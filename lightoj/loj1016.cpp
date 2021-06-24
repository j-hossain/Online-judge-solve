#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
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
    map<int,int> mp;
    vector<int> ys;
    int t,n,w,ans,x,y,flag;
    // cout<<"start\n";
    cin>>t;
    for(int tk=1;tk<=t;tk++){
        cin>>n>>w;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            if(mp[y]==0){
                mp[y]=1;
                ys.push_back(y);
            }
        }
        sort(ys.begin(),ys.end());
        //using x,y vars differently now
        ans=0;
        flag=1;
        x=w;
        for(int i=0;i<ys.size();i++){
            //gotta think something for the logic to take care of the distance
            x=ys[i]+w;
            while(ys[i+1]<=x){
                i++;
            }
            ans++;
        }
        cout<<"Case "<<tk<<": ";
        cout<<ans<<"\n";
        mp.clear();
        ys.clear();
    }
}