#include<iostream>
using namespace std;

int main(){
    int n;
    int arr[4]={6,8,4,2};

    cin>>n;
    if(!n)
    {
        cout<<"1\n";
        return 0;
    }
    cout<<arr[n%4]<<endl;
    return 0;
}
