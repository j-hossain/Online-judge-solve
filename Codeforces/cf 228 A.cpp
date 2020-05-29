#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<long long int> h_shues;
    long long int h,i;
    for(i=0;i<4;i++)
    {
        cin>>h;
        h_shues.insert(h);
    }
    cout<<4-h_shues.size()<<endl;
}
