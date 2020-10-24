#include<iostream>
using namespace std;
//not done yet

struct node{
    int val;
    node* next;
    node* prev;
    node(){
        this->val = 0;
        this->next = NULL;
    }
};

int main(){
    node *list;

    list = NULL;
    int n,sz;
    sz=0;
    while(cin>>n && n){
        if(n==-1){
            cout<<getTheMedian(list,sz)<<endl;
            continue;
        }

        if(list==NULL){

        }
    }


}