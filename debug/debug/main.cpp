#include<iostream>
using namespace std;

int present[27];
int rel[27][27];
string out;
int lim;

void getString(int taken){
    if(out.size()==lim){
        cout<<out<<"\n";
        return;
    }
    for(int i=0;i<27;i++){
        cout<<lim<<"\n";
        if(!(taken&(1<<i)) and present[i]){
            int j;
            for(j=0;j<27;j++){
                if(rel[i][j] and !(taken&(1<<j)))
                    break;
            }
            if(j==27){
                out.push_back('a'+i);
                getString(taken|(1<<i));
                out.pop_back();
            }
        }
    }
}

int main(){
    string chars,cons;
    while(getline(cin,chars)){
        cout<<chars<<"\n";
        for(int i=0;i<27;i++){
            present[i]=0;
        }
        lim=0;
        getline(cin,cons);
        cout<<cons<<"\n";
        // getline(cin,cons);
        for(int i=0;i<chars.size();i+=2){
            present[chars[i]='a']=1;
            lim++;
        }
        for(int i=0;i<cons.size();i+=4){
            rel[cons[i+2]-'a'][cons[i]-'a']=1;
        }
        int taken = 0;
        getString(taken);
    }
    return 0;
}
