#include<iostream>
using namespace std;

int main(){
    char arr[2005];
    int n,p,i;
    bool flag;
    cin>>n>>p;
    cin>>arr;
    flag=false;
    for(i=0;i<n-p;i++){
        if(arr[i]=='.' && arr[i+p]=='.'){
            arr[i]='1';
            arr[i+p]='0';
            flag=true;
        }
        else if(arr[i]=='.' && arr[i+p]!='.'){
            if(arr[i+p]=='0')
                arr[i]='1';
            else
                arr[i]='0';
            flag=true;
        }
        else if(arr[i]!='.' && arr[i+p]=='.'){
            if(arr[i]=='0')
                arr[i+p]='1';
            else
                arr[i+p]='0';
                flag=true;
        }
        if(flag)
            break;
    }

    if(!flag){
        cout<<"No\n";
        return 0;
    }

    for(i=0;i<n;i++){
        if(arr[i]=='.')
            arr[i]='1';
        cout<<arr[i];
    }
    cout<<"\n";
    return 0;
}