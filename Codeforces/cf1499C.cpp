#include<iostream>
#define li long long int
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
    li sm[2],mn[2],cnt[2],arr[100005],i,n,t,sg,ans,temp;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>arr[i];
        }

        mn[0] = arr[0];
        mn[1] = arr[1];
        sm[0] = sm[1] = 0LL;
        cnt[0] = cnt[1] = 1LL;
        ans = n*mn[0]+n*mn[1];

        for(i=2;i<n;i++){
            sg = i%2;
            cnt[sg]++;
            if(arr[i]<mn[sg]){
                sm[sg]+=mn[sg];
                mn[sg] = arr[i];
            }
            else{
                sm[sg]+=arr[i];
            }
            
            temp = sm[0]+mn[0]*(n-cnt[0]+1) + sm[1]+mn[1]*(n-cnt[1]+1);

            ans = min(temp,ans);
            // cout<<ans<<"\n";
        }

        cout<<ans<<"\n";
    }
}