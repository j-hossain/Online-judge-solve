#include<iostream>
#include<algorithm>
using namespace std;
//accepted
int n,a[55],b[55],pos[55][55];

int getAns(int i, int j){
    if(pos[i][j]!=-1)
        return pos[i][j];
    if(i==n)
        return 0;
    if(a[i]<b[j]){
        return pos[i][j] = getAns(i+1,j);
    }

    if(a[i]>b[j]){
        return pos[i][j] = 2+getAns(i+1,j+1);
    }

    return pos[i][j] = max((1+getAns(i+1,j+1)),getAns(i+1,j));
}

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int main(){
    inout();
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        cin>>n;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                pos[i][j]=-1;
        }
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        cout<<"Case "<<tt<<": ";
        cout<<getAns(0,0)<<"\n";
    }
}