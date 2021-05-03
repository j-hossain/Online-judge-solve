#include<iostream>
#include<string>
//accepted

using namespace std;

int main(){
    string out;
    char temp;
    int n,k,mapi[27],i,len,now,nxt;

    cin>>n>>k;


    for(i=0;i<26;i++)
        mapi[i]=0;
    len=0;
    now = 0;

    while(len<n){
        // cout<<"before "<<now<<"\n";
        temp = now+'a';
        out.push_back(temp);
        mapi[now]++;
        if(mapi[now]==k)
            mapi[now]=0;
        now = mapi[now];
        // cout<<"after "<<now<<"\n";
        len++;
    }

    cout<<out<<"\n";
    return 0;
}