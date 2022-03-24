#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//accepted
void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("G:/C programing/Online judges/input.txt","r",stdin);
    freopen("G:/C programing/Online judges/output.txt","w",stdout);
    #endif
}

int checkBigger(char tar, int* mapi){
    for(int i=tar-'a'+1; i<26; i++){
        if(mapi[i])
            return i;
    }
    return -1;
}

int main(){
    inout();
    string inp;
    char bg;
    int mapi[26], i, p, len, s;

    while(1){
        cin>>inp;
        if(inp=="#")
            break;
        len = inp.size();
        for(i=0;i<26;i++)
            mapi[i]=0;
        p=-1;
        mapi[inp[len-1]-'a']++;
        for(i=len-2; i>=0;i--){
            p = checkBigger(inp[i],mapi);
            mapi[inp[i]-'a']++;
            if(p!=-1){
                break;
            }

        }

        if(p==-1){
            cout<<"No Successor\n";
            continue;
        }

        s=i;
        for(i=len-1;i>s;i--){
            if(inp[i]==p+'a'){
                p = i;
                break;
            }
        }
        bg = inp[p];
        for(i=p;i>s;i--)
            inp[i] = inp[i-1];
        inp[s] = bg;

        sort(inp.begin()+s+1, inp.end());

        cout<<inp<<"\n";

    }
    return 0;
}
