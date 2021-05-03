#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main(){
    int n,m,l,num;
    string inp;
    deque<int> dd;
    int t,tk=0;
    cin>>t;
    while(t--){
        tk++;
        cout<<"Case "<<tk<<":\n";
        dd.clear();
        cin>>n>>m;
        l==0;
        for(int i=0;i<m;i++){
            cin>>inp;
            if(inp=="pushLeft"){
                cin>>num;
                if(dd.size()<n){
                    dd.push_front(num);
                    cout<<"Pushed in left: "<<num<<"\n";
                }
                else{
                    cout<<"The queue is full\n";
                }
            }
            else if(inp=="pushRight"){
                cin>>num;
                if(dd.size()<n){
                    dd.push_back(num);
                    cout<<"Pushed in right: "<<num<<"\n";
                }
                else{
                    cout<<"The queue is full\n";
                }
            }
            else if(inp=="popLeft"){
                if(!dd.empty()){
                    num = dd.front();
                    dd.pop_front();
                    cout<<"Popped from left: "<<num<<"\n";
                }
                else{
                    cout<<"The queue is empty\n";
                }
            }
            else{
                if(!dd.empty()){
                    num = dd.back();
                    dd.pop_back();
                    cout<<"Popped from right: "<<num<<"\n";
                }
                else{
                    cout<<"The queue is empty\n";
                }
            }
        }
    }
    return 0;
    
}