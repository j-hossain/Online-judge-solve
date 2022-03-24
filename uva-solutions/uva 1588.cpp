#include<iostream>
#include<string>

using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int main(){

    inout();
    string s1,s2,temp;
    int i,j;

    while(cin>>s1>>s2){

        int sz1 = s1.size();
        int sz2 = s2.size();
        if(sz1<sz2){
            temp = s1;
            s1 = s2;
            s2 = temp;

            sz1 = sz1+sz2;
            sz2 = sz1-sz2;
            sz1 = sz1-sz2;
        }
        int ans = sz1+sz2;
        for(i=-sz2;i<=sz1;i++){
            int flag = 1;
            for(j=0;j<sz2 && flag;j++){
                if(i+j>=0 && i+j<sz1){
                    flag &= (s1[i+j]-'0'+s2[j]-'0')<=3;
                }
            }

            if(flag){
                ans = min(ans, max(sz1,i+sz2)-min(i,0));
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}