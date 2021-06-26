#include<iostream>
#include<string>
using namespace std;

#define alw cout<<al<<"\n";
#define bbw cout<<bb<<"\n";
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
    string name,al="Alice",bb="Bob";
    int t,n,ans;
    
    cin>>t;
    for(int tk=1;tk<=t;tk++){
        cin>>n>>name;
        ans=n%3;
        cout<<"Case "<<tk<<": ";
        if(name==al){
            if(ans==1)
                bbw
            else
                alw
        }
        else if(name==bb){
            if(ans==0)
                alw
            else
                bbw
        }
    }
    return 0;
}