#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define mx 100005
int k,freq[mx],uni,arr[mx];

//accepted


void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

struct query
{
    int l;
    int r;
    int i;
    bool operator<(const query &a)const{
        int x = l/k;
        int y = a.l/k;
        if(x==y){
            return r<a.r;
        }
        return x<y;
    }
};

query qq[50003];

void add(int i){
    freq[arr[i]]++;
    if(freq[arr[i]]==1){
        uni++;
    }
}

void remove(int i){
    freq[arr[i]]--;
    if(freq[arr[i]]==0){
        uni--;
    }
}

int main(){
    inout();
    int t, n,q,ans[50005];
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        cin>>n>>q;
        k = sqrt(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            freq[arr[i]] = 0;
        }
        for(int i=0;i<q;i++){
            cin>>qq[i].l>>qq[i].r;
            qq[i].l--;
            qq[i].r--;
            qq[i].i = i;
        }
        sort(qq,qq+q);
        int l = 0;
        int r = -1;
        uni = 0;
        for(int i=0;i<q;i++){
            while(l<qq[i].l){
                remove(l);
                l++;
            }
            while(l>qq[i].l){
                l--;
                add(l);
            }
            while(r<qq[i].r){
                r++;
                add(r);
            }
            while(r>qq[i].r){
                remove(r);
                r--;
            }
            ans[qq[i].i] = uni;
        }
        cout<<"Case "<<cs<<":\n";
        for(int i=0;i<q;i++)
            cout<<ans[i]<<"\n";
    }
    return 0;
}