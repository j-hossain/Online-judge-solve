#include<iostream>
#include<algorithm>
using namespace std;


void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

typedef struct {
    long long int cost;
    long long int type;
}dish;

long long int n,e,h;
dish dishes[4];

bool ifPossible(long long int se,long long int now){
    int sum = e+h;
    if(se==1){
        if(e>=2)
            sum-=2;
        else
            return false;
    }
    else if(se==2){
        if(h>=3){
            sum-=3;
        }
        else
            return false;
    }
    else if(se==3){
        if(e>=1 && h>=1)
            sum-=2;
        else
            return false;
    }

    if(sum>=(n-now)*2)
        return true;
    return false;
}

void take(long long int se){
    
    if(se==1){
        e-=2;
    }
    else if(se==2){
        h-=3;
    }
    else if(se==3){
        e--;
        h--;
    }
}

bool comp(dish a, dish b){
    return a.cost<b.cost;
}

int main(){
    inout();
    long long int i,ans,t;

    cin>>t;
    while(t--){
        cin>>n>>e>>h;
        for(i=1;i<=3;i++){
            cin>>dishes[i].cost;
            dishes[i].type = i;
        }

        sort(dishes+1,dishes+4,comp);
        ans=0LL;
        for(i=1;i<=n;i++){
            bool flag = false;
            for(int j=1;j<=3;j++){
                if(ifPossible(dishes[j].type,i)){
                    flag=true;
                    take(dishes[j].type);
                    ans+=dishes[j].cost;
                    break;
                }
            }
            if(!flag){
                ans=-1;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}

