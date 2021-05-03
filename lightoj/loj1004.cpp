#include<iostream>
using namespace std;
#define ll long long int
#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}
ll grph[250][250],updt[250][250],i,j,n,t,l,r,temp,tk;

int main(){
    inout();
    fast();
    cin>>t;
    tk=0;
    while(t--){
        tk++;
        cin>>n;

        for(i=0;i<n-1;i++){
            for(j=0;j<=i;j++){
                cin>>grph[i][j];
                updt[i][j]=grph[i][j];
            }
        }

        for(i=0;i<n;i++){
            for(j=0;j<n-i;j++){
                cin>>grph[i+n-1][j];
                updt[i+n-1][j]=grph[i+n-1][j];
            }
        }

        for(i=0;i<n-1;i++){
            for(j=0;j<=i;j++){
                // cout<<updt[i][j]<<" ";

                temp = updt[i][j]+grph[i+1][j];
                if(temp>updt[i+1][j]){
                    updt[i+1][j]=temp;
                }
                temp = updt[i][j]+grph[i+1][j+1];
                if(temp>updt[i+1][j+1]){
                    updt[i+1][j+1]=temp;
                }
            }
            // cout<<"\n";
        }
        for(i=0;i<n;i++){
            for(j=0;j<n-i;j++){
                // cout<<updt[i+n-1][j]<<" ";
                int prv=j, ths = n-i-1-j;
                if(prv!=0){
                    temp =updt[i+n-1][j]+grph[i+n][j-1];

                    if(temp>updt[i+n][j-1])
                        updt[i+n][j-1] = temp;
                }
                if(ths!=0){
                    temp =updt[i+n-1][j]+grph[i+n][j];

                    if(temp>updt[i+n][j])
                        updt[i+n][j] = temp;
                }
            }
            // cout<<"\n";
        }
        cout<<"Case "<<tk<<": ";
        cout<<updt[2*n-2][0]<<"\n";
    }
}