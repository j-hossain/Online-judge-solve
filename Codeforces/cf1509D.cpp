#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
//accepted
using namespace std;

#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

typedef struct{
    string main;
    int num[2];
}lit;

void setAll(lit &a){
    int prv = 0;
    a.num[0]=a.num[1]=0;
    for(int i=0;i<a.main.size();i++){
        a.num[a.main[i]-'0']++;
    }
}

void buildString(string &st,lit &a, lit &b, int dg, int n){
    int prev[2];
    prev[0]=0;
    prev[1]=0;
    char x = dg+'0';
    for(int i=0;i<n;i++){
        while(1){
            if(a.main[prev[0]]==x){
                prev[0]++;
                break;
            }
            st.push_back(a.main[prev[0]++]);
            if(prev[0]==2*n)
                break;
        }
        while(1){
            if(b.main[prev[1]]==x){
                prev[1]++;
                break;
            }
            st.push_back(b.main[prev[1]++]);
            if(prev[1]==2*n)
                break;
        }
        if(st.size()<3*n)
            st.push_back(dg+'0');
    }
    for(int j=prev[0];j<a.main.size();j++){
        st.push_back(a.main[j]);
    }
    for(int j=prev[1];j<b.main.size();j++){
        st.push_back(b.main[j]);
    }
}

lit three[3];

int main(){
    fast();
    inout();
    int t,n,i;
    string out;
    vector<int> sames;

    cin>>t;
    while(t--){
        out.clear();
        cin>>n;
        for(i=0;i<3;i++){
            cin>>three[i].main;
        }

        for(i=0;i<3;i++){
            setAll(three[i]);
            // print(three[i]);
        }

        for(i=0;i<2;i++){
            for(int j=i+1;j<3;j++){
                if(three[i].num[0]>=n && three[j].num[0]>=n){
                    buildString(out,three[i],three[j],0,n);
                    break;
                }
                else if(three[i].num[1]>=n && three[j].num[1]>=n){
                    buildString(out,three[i],three[j],1,n);
                    break;
                }
            }
            if(!out.empty())
                break;
        }
        cout<<out<<"\n";
    }
    return 0;
}